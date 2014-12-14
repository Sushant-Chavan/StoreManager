#ifndef DEFINES_H
#define DEFINES_H

namespace defines {

namespace primaryHmiButtons {
enum primaryHmiButtons
{
    CREATE_BILL = 0,
    SEARCH_ITEM_CODE,
    SEARCH_ITEM_PRICE,
    DISPLAY_INVENTORY,
    ADD_ITEM_TO_INVENTORY,
    REMOVE_ITEM_FROM_INVENTORY
};
}

namespace createBillButtons {
enum createBillButtons
{
    ADD_TO_BILL = 0,
    REMOVE_FROM_BILL,
    SHOW_BILL,
    FINALIZE_BILL
};
}

namespace addItemToInventory {
enum addItemToInventory
{
    ADD_TO_INVENTORY = 0,
    CANCEL
};
}


namespace removeItemFromInventory {
enum removeItemFromInventory
{
    REMOVE_FROM_INVENTORY = 0,
    CANCEL
};
}

}
#endif // DEFINES_H
