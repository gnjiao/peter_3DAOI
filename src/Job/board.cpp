#include "board.hpp"

using namespace Job;

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//constructor & destructor function
Board::Board()
{

}

Board::~Board()
{

}
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//write & print
void Board::writeToXml(QDomDocument doc, QDomElement job)
{
    //将内存中的Board信息写入xml文件中
    QDomElement board = doc.createElement("Board");
    board.setAttribute("name",QString::fromStdString(this->name()));
    board.setAttribute("originalX",QString::number(this->originalX()));
    board.setAttribute("originalY",QString::number(this->originalY()));
    board.setAttribute("sizeX",QString::number(this->sizeX()));
    board.setAttribute("sizeY",QString::number(this->sizeY()));
    job.appendChild(board);

    //将内存中的MeasuredObj信息写入xml文件中
    Job::MeasuredObj* pTemp = nullptr;
    pTemp = this->measuredList().pHead();
    while ( nullptr != pTemp )
    {
        std::string name = pTemp->name();

        QDomElement element = doc.createElement(QString::fromStdString(name));
        element.setAttribute("x",QString::number(pTemp->body().xPos()));
        element.setAttribute("y",QString::number(pTemp->body().yPos()));
        element.setAttribute("angle",QString::number(pTemp->body().angle()));
        element.setAttribute("width",QString::number(pTemp->body().width()));
        element.setAttribute("height",QString::number(pTemp->body().height()));
        board.appendChild(element);
        pTemp = pTemp->pNext();
    }
}

void Board::print()
{
    //在终端打印Board名字,原点位置,长宽尺寸信息.
    std::cout<<std::setw(20)<<std::left<<"Board:"<<m_name<<std::endl
             <<std::setw(20)<<std::left<<"original x:"<<m_originalX<<std::endl
             <<std::setw(20)<<std::left<<"original y:"<<m_originalY<<std::endl
             <<std::setw(20)<<std::left<<"size x:"<<m_sizeX<<std::endl
             <<std::setw(20)<<std::left<<"size y:"<<m_sizeY<<std::endl
             <<std::endl;

    //调用print函数
    m_measureList.print();
}
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
