#include "passwdlineedit.h"

passwdLineEdit::passwdLineEdit(QWidget *parent)
	: QLineEdit(parent)
{
	//�������Ҽ��˵�
	this->setContextMenuPolicy(Qt::NoContextMenu);
	//����������ʾ
	this->setPlaceholderText(QString(tr("please input password...")));
	//������������
	this->setEchoMode(QLineEdit::Password);
	//������󳤶�32λ
	this->setMaxLength(32);
}

passwdLineEdit::~passwdLineEdit()
{

}

//���������ȫѡ�����ơ�ճ������
void passwdLineEdit::keyPressEvent(QKeyEvent *event)
{
	if(event->matches(QKeySequence::SelectAll))
	{   
		return ;   
	}
	else if(event->matches(QKeySequence::Copy))
	{   
		return ;   
	}
	else if(event->matches(QKeySequence::Paste))
	{   
		return ;   
	}
	else
	{
		QLineEdit::keyPressEvent(event);
	}
} 

//�������λ���������ʱ�����ƶ�
void passwdLineEdit::mouseMoveEvent(QMouseEvent *)
{
	return ;
}

//�������˫����Ч
void passwdLineEdit::mouseDoubleClickEvent(QMouseEvent *event)
{
	return ;
}
