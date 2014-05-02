#include <QToolButton>
#include <QStyle>

#include "lineedit.h"

EnchancedLineEdit::EnchancedLineEdit(QWidget *parent)
    : QLineEdit(parent)
{
    // Create a clear button with icon
    clearBtn = new QToolButton(this);
    QIcon icon = QIcon::fromTheme("edit-clear", QIcon(":/images/icon"));
    clearBtn->setIcon( icon );
    clearBtn->setCursor(Qt::ArrowCursor);
    clearBtn->setStyleSheet("QToolButton { border: none; padding: 0px; }");
    clearBtn->hide();

    // signals, clear lineEdit if btn pressed; change btn visibility on input
    connect(clearBtn, SIGNAL(clicked()), this, SLOT(clear()) );
    connect(this, SIGNAL(textChanged(const QString&)),
            this, SLOT  (updateCloseButton(const QString&)));

    int frameWidth = style()->pixelMetric(QStyle::PM_DefaultFrameWidth);
    setStyleSheet(QString("QLineEdit { padding-right: %1px; } ").arg(clearBtn->sizeHint().width() + frameWidth + 1));
    QSize msz = minimumSizeHint();
    setMinimumSize(qMax(msz.width(),  clearBtn->sizeHint().height() + frameWidth * 2 + 2),
                   qMax(msz.height(), clearBtn->sizeHint().height() + frameWidth * 2 + 2));
}

EnchancedLineEdit::~EnchancedLineEdit() {}

void EnchancedLineEdit::resizeEvent(QResizeEvent *)
{
    QSize sz = clearBtn->sizeHint();
    int frameWidth = style()->pixelMetric(QStyle::PM_DefaultFrameWidth);
    clearBtn->move(rect().right() - frameWidth - sz.width(),
                      (rect().bottom() + 1 - sz.height())/2);
}

void EnchancedLineEdit::updateCloseButton(const QString& text)
{
    clearBtn->setVisible(!text.isEmpty());
}
