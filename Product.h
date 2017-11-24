//
// Created by Xiaochen Wang on 2017-11-23.
//

#ifndef W7_PRODUCT_H
#define W7_PRODUCT_H
#include "iProduct.h"

namespace w7{
    class Product : public iProduct{
        int product_number_;
        double cost_;
    public:
        Product(int product_number, double cost);
        virtual double getCharge() const;
        virtual void display(std::ostream& os) const;

    };

    class TaxableProduct : public Product {
        char taxable_status_;
    public:
        TaxableProduct(int product_number, double cost, char taxable_status);
        virtual double getCharge() const;
        virtual void display(std::ostream& os) const;
    };

}


#endif //W7_PRODUCT_H
