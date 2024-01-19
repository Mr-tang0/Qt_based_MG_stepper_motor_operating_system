#include "systemset_window.h"
#include "ui_systemset_window.h"
#include "test_window.h"
#include "portui_window.h"

systemSet::systemSet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::systemSet),
    m_snackbar(new QtMaterialSnackbar)
{
    ui->setupUi(this);
    m_snackbar->setParent(this);
    m_snackbar->setBackgroundColor(QColor(150,150,150));
    m_snackbar->setFont(QFont("幼圆"));

    group = new QButtonGroup(this);
    group->addButton(ui->Compression);
    group->addButton(ui->stretching);
    group->addButton(ui->Reciprocating);
    group->addButton(ui->Manually);
    group->addButton(ui->Customize);


    //connect(mainUiTest::myPort,&portUi::portConnected,&systemSet::freshPort);



}

systemSet::~systemSet()
{
    delete ui;
}

void systemSet::freshPort()
{
    ui->SerialPort->setCurrentText(mainUiTest::myPort->portName());
    qDebug()<<"in"<<mainUiTest::myPort->portName();
}

void systemSet::on_submitBtn_clicked()
{
    saveLabel("D:/QT/testfile.csv");
}

void systemSet::saveLabel(QString filePath)//保存csv文件并且更新port、motor和weigh地址
{

    QList<QStringList> data;
    data.append({"User",ui->ExperimenterEdit->text()});
    data.append({"Number",ui->timeNumberEdit->text()});

    data.append({"Material",ui->MaterialEdit->text()});
    data.append({"Sample",ui->sampleEdit->text()});

    data.append({"CurrentTime",ui->currentTime->text()});
    data.append({"number",ui->timeNumberEdit->text()});

    data.append({"area",ui->areaEdit->text()});
    data.append({"length",ui->lengthEdit->text()});

    data.append({"size",ui->sizeEdit->text()});
    data.append({"strainRate",ui->strainRateEdit->text()});

    data.append({"more",ui->moreEdit->text()});
    data.append({"strainRate",ui->strainRateEdit->text()});

    QString testManner = "";
    QObject *selectBtn = group->checkedButton();
    if(selectBtn)
    {
        testManner = selectBtn->property("text").toString();
    }

    data.append({"test manner",testManner});

    data.append({"strainRate",ui->strainRateEdit->text()});

    saveCsvFile(filePath,data);



}

void systemSet::saveCsvFile(QString filePath,QList<QStringList> data)
{
    QFile labelFile(filePath);

    if(!labelFile.open(QIODevice::ReadOnly))
    {
        labelFile.open(QIODevice::WriteOnly);
        labelFile.write("");
        m_snackbar->addMessage("保存成功");
    }
    else {
        m_snackbar->addMessage("当前位置已存在文件,不可覆盖");
        return;
    }

    for (int i =0;i<data.length();i++)
    {
        for (int j = 0;j<data[i].length();j++)
        {
            labelFile.write(data[i][j].toUtf8().toStdString().c_str());
            labelFile.write(",");
        }
        labelFile.write("\n");
    }
    labelFile.close();

}


