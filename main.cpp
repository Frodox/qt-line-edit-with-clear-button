/* Encanced line edit, with clear button shown, when there is some text on QLineEdit
 * Useful for Search fields
 * Reference:
 * http://blog.qt.digia.com/blog/2007/06/06/lineedit-with-a-clear-button/
 **/

#include <QApplication>

#include "lineedit.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EnchancedLineEdit ele;
    ele.show();

    return a.exec();
}
