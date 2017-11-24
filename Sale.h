//
// Created by Xiaochen Wang on 2017-11-23.
//

#ifndef W7_SALE_H
#define W7_SALE_H
#include <vector>
#include "Product.h"

namespace w7{
    class Sale {
        std::vector<iProduct*> products;

    public:
        Sale(const char* file);
        virtual ~Sale();

        void display(std::ostream& os) const;
    };

}
#endif
