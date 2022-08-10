#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QClipboard>
#include <QString>
#include <iostream>
#include <set>
#include <map>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected slots:
    void on_pushButton_clicked();
private slots:
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QClipboard *clipboard;
    QString swaped_text;
    std::set<QString> eng_alphabet = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    std::set<QString> rus_alphabet = {QString::fromUtf8("а"),
                                      QString::fromUtf8("б"),
                                      QString::fromUtf8("в"),
                                      QString::fromUtf8("г"),
                                      QString::fromUtf8("д"),
                                      QString::fromUtf8("е"),
                                      QString::fromUtf8("ё"),
                                      QString::fromUtf8("ж"),
                                      QString::fromUtf8("з"),
                                      QString::fromUtf8("и"),
                                      QString::fromUtf8("й"),
                                      QString::fromUtf8("к"),
                                      QString::fromUtf8("л"),
                                      QString::fromUtf8("м"),
                                      QString::fromUtf8("н"),
                                      QString::fromUtf8("о"),
                                      QString::fromUtf8("п"),
                                      QString::fromUtf8("р"),
                                      QString::fromUtf8("с"),
                                      QString::fromUtf8("т"),
                                      QString::fromUtf8("у"),
                                      QString::fromUtf8("ф"),
                                      QString::fromUtf8("х"),
                                      QString::fromUtf8("ц"),
                                      QString::fromUtf8("ч"),
                                      QString::fromUtf8("ш"),
                                      QString::fromUtf8("щ"),
                                      QString::fromUtf8("ъ"),
                                      QString::fromUtf8("ы"),
                                      QString::fromUtf8("ь"),
                                      QString::fromUtf8("э"),
                                      QString::fromUtf8("ю"),
                                      QString::fromUtf8("я")};
    std::map<QString, QString> eng_to_rus = {
        {"a", "ф"},
        {"b", "и"},
        {"c", "с"},
        {"d", "в"},
        {"e", "у"},
        {"f", "а"},
        {"g", "п"},
        {"h", "р"},
        {"i", "ш"},
        {"j", "о"},
        {"k", "л"},
        {"l", "д"},
        {"m", "ь"},
        {"n", "т"},
        {"o", "щ"},
        {"p", "з"},
        {"q", "й"},
        {"r", "к"},
        {"s", "ы"},
        {"t", "е"},
        {"u", "г"},
        {"v", "м"},
        {"w", "ц"},
        {"x", "ч"},
        {"y", "н"},
        {"z", "я"}
    };
    std::map<QString, QString> rus_to_eng = {
        {"а", "f"},
        {"б", ","},
        {"в", "d"},
        {"г", "u"},
        {"д", "l"},
        {"е", "t"},
        {"ё", "`"},
        {"ж", ";"},
        {"з", "p"},
        {"и", "b"},
        {"й", "q"},
        {"к", "r"},
        {"л", "k"},
        {"м", "v"},
        {"н", "y"},
        {"о", "j"},
        {"п", "g"},
        {"р", "h"},
        {"с", "c"},
        {"т", "n"},
        {"у", "e"},
        {"ф", "a"},
        {"х", "["},
        {"ц", "w"},
        {"ч", "x"},
        {"ш", "i"},
        {"щ", "o"},
        {"ъ", "]"},
        {"ы", "s"},
        {"ь", "m"},
        {"э", "'"},
        {"ю", "."},
        {"я", "z"}
    };

    const int w_width = 350;
    const int w_heigth = 155;

    bool is_eng(QString s);

    bool is_rus(QString s);

    QString swap();
    std::vector<QString> swap2();
};
#endif // MAINWINDOW_H
