#ifndef _H_K_BUTTON_
#define _H_K_BUTTON_

#include <QPushButton>

class KPushButton : public QPushButton{
Q_OBJECT
  public:

  KPushButton(QWidget *parent = nullptr):QPushButton(parent){

  }
  KPushButton(const QString &text, QWidget *parent = nullptr):QPushButton(text,parent){

  }
  KPushButton(const QIcon &icon, const QString &text, QWidget *parent = nullptr):QPushButton(icon,text,parent){

  }

  private:

};


#endif