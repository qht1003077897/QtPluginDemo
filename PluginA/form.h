#pragma once

#include "ui_form.h"
#include <QWidget>

namespace Ui {
class form;
}

class form : public QWidget
{
    Q_OBJECT

public:
    explicit form(QWidget *parent = nullptr);
    ~form();
    void setPlugin(std::function<void(QWidget *widget)> callback);
public slots:
    void clickOpenImg();
    void click2Animation();
signals:
    void animation(QWidget*);
private:
    std::function<void(QWidget *widget)> m_callback;
    Ui::form *ui;
};

