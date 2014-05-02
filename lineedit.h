#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <QLineEdit>

class QToolButton;

class EnchancedLineEdit : public QLineEdit
{
    Q_OBJECT

public:
    EnchancedLineEdit(QWidget *parent = 0);
    ~EnchancedLineEdit();

protected:
  void resizeEvent(QResizeEvent *);

private:
    QToolButton *clearBtn;

private slots:
    void updateCloseButton(const QString &text);
};

#endif // LINEEDIT_H
