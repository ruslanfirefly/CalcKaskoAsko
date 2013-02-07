#include <QtGui>

#include "dateDelegate.h"
DateDelegate::DateDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}
QWidget *DateDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    QDateEdit *editor = new QDateEdit(parent);
    editor->setDisplayFormat("dd.MM.yy");
    editor->setDate(QDate::currentDate());
    return editor;
}
void DateDelegate::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const
{
    QDate value = index.model()->data(index, Qt::EditRole).toDate();

    QDateEdit *dateEdit = static_cast<QDateEdit*>(editor);
    dateEdit->setDate(value);
}
void DateDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                   const QModelIndex &index) const
{
    QDateEdit *dateEdit = static_cast<QDateEdit*>(editor);
    QDate value = dateEdit->date();
    model->setData(index, value, Qt::EditRole);
}
void DateDelegate::updateEditorGeometry(QWidget *editor,
    const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}

QString DateDelegate::displayText(const QVariant &value, const QLocale &locale) const
{
    return locale.toString(value.toDate(), "dd:MM:yy");
}
