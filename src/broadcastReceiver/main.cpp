#include <QtWidgets>
#include "receiver.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Receiver receiver;
    return a.exec();
}
