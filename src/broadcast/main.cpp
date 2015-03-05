#include <QCoreApplication>

#include "sender.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Sender sender;

    return a.exec();
}
