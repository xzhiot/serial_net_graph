#include "dataprocess.h"

DataProcess::DataProcess()
{
    fullsize = 4096;
    startFlag = false;
    loc = 0;
}

bool DataProcess::process(char *output,uint16_t* count)
{
    unsigned int starttemp = 0;
    starttemp = isStart();
    if(startFlag || starttemp!=0xffffffff)//如果收到包头标志，开始处理
    {
        //预处理
        if(startFlag==false)
        {
            startFlag=true;
            data=data.mid(starttemp);
            loc=0;
        }
        //如果接收完成，正式处理
        loc=isEnd();
        if(loc)
        {
            for(int i=0;i<loc/4-1;i++)
            {
                output[i*4+3]=data.at(i*4+4);
                output[i*4+2]=data.at(i*4+5);
                output[i*4+1]=data.at(i*4+6);
                output[i*4+0]=data.at(i*4+7);
            }
            data=data.mid(loc);
            *count = loc/4-1;
            startFlag=false;
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

unsigned int DataProcess::isStart()
{
    if(data.size()<4)
        return 0xffffffff;
    for(int i=0;i<data.size()-3;i++)
    {
        if((uint8_t)(data.at(i))==0xAA)
            if((uint8_t)(data.at(i+1))==0xAA)
                if((uint8_t)(data.at(i+2))==0xF1)
                    //if((uint8_t)(data.at(i+3))==0)
                    {
                        //if(data.size()-data.at(i+3)<5)
                         //   return 0xffffffff;
                        //else
                            return i;
                    }
    }
    return 0xffffffff;
}

int DataProcess::isEnd()
{
      if(data.size()<=9)
        return 0;
      uint8_t len = data.at(3);

      if(data.size()>=(4+len+1))
      {
        char checksum = 0;
        for (int i = 0; i < len + 4; i++)//len+3表示校验之前的位置
        {
            checksum += data.at(i);
        }
        if (checksum == data.at(len + 4)) //如果数据校验失败，丢弃这一包数据
        {
          //this->data.remove(0, len + 4);//从缓存中删除错误数据

            return 4+len+1;//继续下一次循环
        }
        else
        {
            qDebug()<<"sum error";
            data=data.mid(3);
            startFlag=false;
            return 0;
        }
      }
    return 0;
}

bool DataProcess::isFull()
{
    if(data.size()>=fullsize)
        return true;
    return false;
}

int DataProcess::getFullsize() const
{
    return fullsize;
}

void DataProcess::setFullsize(int value)
{
    fullsize = value;
}

void DataProcess::add(QByteArray &input)
{
    data.append(input);
    //判断是否接受超量
    if(isFull())
    {
        startFlag=false;
        loc=0;
        data=data.mid(input.size());
    }
    
}

void DataProcess::clear()
{
    data.clear();
    startFlag=false;
    loc=0;
}
