#ifndef PRIMARYHMI_H
#define PRIMARYHMI_H

#include <QWidget>

namespace Ui {
class PrimaryHMI;
}

class PrimaryHMI : public QWidget
{
    Q_OBJECT

public:
    explicit PrimaryHMI(QWidget *parent = 0);
    ~PrimaryHMI();

private:
    Ui::PrimaryHMI *ui;

public slots:
    void createBill();
    void searchItemCode();
    void searchItemPrice();
    void displayInventory();
    void addItemToInventory();
    void removeItemFromInventory();
};

#endif // PRIMARYHMI_H
