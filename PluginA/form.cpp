#include "form.h"

#include <QFileDialog>
#include <QPixmap>
form::form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::form)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(clickOpenImg()));
    connect(ui->pushButton2,SIGNAL(clicked()),this,SLOT(click2Animation()));
}

form::~form()
{
    delete ui;
}

void form::setPlugin(std::function<void(QWidget *widget)> callback)
{
    m_callback = std::move(callback);
}


void form::clickOpenImg()
{
    QString path = QFileDialog::getOpenFileName(this, tr("选择图片"), ".", tr("Image Files(*.jpg *.png)"));
    ui->label->setPixmap(QPixmap(path));
}

void form::click2Animation()
{
    m_callback(ui->label);
}
