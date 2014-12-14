#ifndef CREATEBILL_H
#define CREATEBILL_H

#include <QWidget>
#include "Defines.h"

namespace Ui {
class CreateBill;
}

class CreateBill : public QWidget
{
    Q_OBJECT

public:
    explicit CreateBill(QWidget *parent = 0);
    ~CreateBill();

private:
    Ui::CreateBill *ui;

signals:
    void createBillSignal(defines::createBillButtons::createBillButtons button);

public slots:
    void addItemSlot();
    void removeItemSlot();
    void showBillSlot();
    void finalizeBillSlot();
};

#endif // CREATEBILL_H
