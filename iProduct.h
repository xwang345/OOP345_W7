//
// Created by Xiaochen Wang on 2017-11-23.
//

#ifndef W7_IPRODUCT_H
#define W7_IPRODUCT_H

#include <iostream>
#include <fstream>

namespace w7 {
    class iProduct {
    public:
        virtual double getCharge() const = 0;
        virtual void display(std::ostream&) const = 0;
    };
    std::ostream& operator<<(std::ostream&, const iProduct&);
    iProduct* readProduct(std::ifstream&);

}

#endif //W7_IPRODUCT_H
