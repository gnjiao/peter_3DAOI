#include "board.hpp"

using namespace Job;

Board::Board()
{

}

Board::~Board()
{

}

void Board::writeToXml(QDomDocument doc, QDomElement job)
{
    QDomElement board = doc.createElement("Board");
    board.setAttribute("name",QString::fromStdString(this->name()));
    board.setAttribute("originalX",QString::number(this->originalX()));
    board.setAttribute("originalY",QString::number(this->originalY()));
    board.setAttribute("sizeX",QString::number(this->sizeX()));
    board.setAttribute("sizeY",QString::number(this->sizeY()));
    job.appendChild(board);

    Job::MeasuredObj* pTemp = this->measuredList().pHead();
    const int cnt = this->measuredList().size();
    for(int i = 0; i < cnt; ++i )
    {
        std::string name = pTemp->name();

        QDomElement element = doc.createElement(QString::fromStdString(name));
        element.setAttribute("x",QString::number(pTemp->body().xPos()));
        element.setAttribute("y",QString::number(pTemp->body().yPos()));
        element.setAttribute("width",QString::number(pTemp->body().width()));
        element.setAttribute("height",QString::number(pTemp->body().height()));
        board.appendChild(element);
        pTemp = pTemp->pNext();
    }
    pTemp = nullptr;
}

void Board::print()
{
    std::cout<<std::setw(20)<<std::left<<"Board:"<<m_name<<std::endl
             <<std::setw(20)<<std::left<<"original x:"<<m_originalX<<std::endl
             <<std::setw(20)<<std::left<<"original y:"<<m_originalY<<std::endl
             <<std::setw(20)<<std::left<<"size x:"<<m_sizeX<<std::endl
             <<std::setw(20)<<std::left<<"size y:"<<m_sizeY<<std::endl
             <<std::endl;

    m_measureList.print();
}
