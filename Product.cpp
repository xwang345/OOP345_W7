//
// Created by Xiaochen Wang on 2017-11-23.
//

#include <iomanip>
#include "Product.h"
using namespace std;
namespace w7{
    iProduct* readProduct(ifstream& in)
    {
        int pn;
        double cost;
        char ts;

        in >> pn;
        if (in.fail())
            return (iProduct*) 0;
        in >> cost;
        if (in.fail())
            return (iProduct*) 0;

        ts = in.get();
        if(ts != '\n'){
            in >> ts;
            return new TaxableProduct(pn,cost,ts);
        } else {
            return new Product(pn,cost);
        }
    }

    Product::Product(int product_number, double cost){
        product_number_ = product_number;
        cost_ = cost;
    }

    double Product::getCharge() const{
        return cost_;
    }

    void Product::display(std::ostream& os) const
    {
        os << setw(10) << product_number_ << fixed << setprecision(2);
        os << setprecision(2) << setw(10) << cost_;
    }

    TaxableProduct::TaxableProduct(int product_number, double cost,char taxable_status):Product(product_number,cost)
    {
        taxable_status_ = taxable_status;
    }

    double TaxableProduct::getCharge() const {
        double charge = Product::getCharge();
        (taxable_status_ == 'H') ? charge *= 1.13 : charge *= 1.08;
        return charge;
    }

    void TaxableProduct::display(std::ostream& os) const{
        Product::display(os);
        os << ' ';
        (taxable_status_ == 'H') ? os << "HST" : os << "PST";
    }

    std::ostream& operator<<(std::ostream& os, const iProduct& P) {
        P.display(os);
        return os;
    }

}


