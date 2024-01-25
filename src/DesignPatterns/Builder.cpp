#include <iostream>
#include <string>

 struct ProductViewModel{
      int Id; 
      std::string CategoryName; 
      std::string ProductName; 
      float UnitPrice; 
      float DiscountedPrice;
      bool DiscountApplied;
 };



class ProductBuilder{
    public:
       virtual void GetProductData() const = 0;
       virtual void ApplyDiscount() const = 0;
       virtual ProductViewModel GetModel() const = 0;
};

class NewCustomerProductBuilder :public ProductBuilder{
public:

    ProductViewModel* model = new ProductViewModel();

    void GetProductData() const override 
    {
        model->Id = 1;
        model->CategoryName = "Beverages";
        model->ProductName = "Chai";
        model->UnitPrice = 20;
    }
    
    void ApplyDiscount() const override 
    {
        model->DiscountedPrice = model->UnitPrice * 0.90f;
        model->DiscountApplied = true;
    }
    
    ProductViewModel GetModel() const override 
    {
        return *model;
    }
};

class OldCustomerProductBuilder :public ProductBuilder{
public:

    ProductViewModel* model = new ProductViewModel();

    void GetProductData() const override 
    {
        model->Id = 1;
        model->CategoryName = "Beverages";
        model->ProductName = "Chai";
        model->UnitPrice = 20;
    }
    
    void ApplyDiscount() const override 
    {
        model->DiscountedPrice = model->UnitPrice;
        model->DiscountApplied = false;
    }
    
    ProductViewModel GetModel() const override 
    {
        return *model;
    }
};


class ProductDirector{
public:
    void GenerateProduct(ProductBuilder* productBuilder){
        productBuilder->GetProductData();
        productBuilder->ApplyDiscount();
    }

};

/*

int main() {

    ProductDirector director;

    OldCustomerProductBuilder* obuilder = new OldCustomerProductBuilder();
    NewCustomerProductBuilder* nbuilder = new NewCustomerProductBuilder();


    director.GenerateProduct(obuilder);
    director.GenerateProduct(nbuilder);

    
    ProductViewModel model = obuilder->GetModel();
    //ProductViewModel model = obuilder->GetModel();

    std::cout<<"model.Id :"<< model.Id <<std::endl;
    std::cout<<"model.CategoryName :"<< model.CategoryName <<std::endl;
    std::cout<<"model.DiscountApplied :"<< model.DiscountApplied <<std::endl;
    std::cout<<"model.DiscountedPrice :"<< model.DiscountedPrice <<std::endl;
    std::cout<<"model.ProductName :"<< model.ProductName <<std::endl;
    std::cout<<"model.UnitPrice :"<< model.UnitPrice <<std::endl;
 
    return 0;
}


*/