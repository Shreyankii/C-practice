#include <iostream>
using namespace std;
class item {
    
    private:
    string name;
    int id;
    float price;

    
    protected :
    int quantity;
    
    public:
    item(string name,int id,float price,int quantity){
        
        this -> name = name;
        this -> id = id;
        this -> price = price;
        this -> quantity= quantity;
        
    }
    
    void display(){
        
        std::cout <<"item :" <<name  << std::endl;
        std::cout << "id is "<<id  << std::endl;
        std::cout << "price is "<<price<< std::endl;
        std::cout << "quantity"<<quantity  << std::endl;
    }
    
    float getTotalValue(){
        
        
        return price*quantity;
    }
    
    ~item() {
        cout << "Base Item destroyed: " << name << endl;
    }
    

};

class Electronics : public item{
    public:
    int warrantyyears;
    float powerusage;
    
   
    Electronics
    (string name,int id,float price,int quantity,int warrantyyears,float powerusage)
    
    
    : item(name,id,price,quantity){
    
    this -> warrantyyears= warrantyyears;
    this -> powerusage=powerusage;
    }
   
     void displayDetails() {
        display();
        cout << "Warranty (years): " << warrantyyears
             << "\nPower Usage: " << powerusage << "W" << endl;
    }
    
    
     ~Electronics() {
        cout << "Electronics object destroyed.\n";
    }
    
};

class Grocery : public item {
public:
    string expiryDate;
    float weight;

public:
    Grocery
    (string name,int id,float price,int quantity,string expiryDate,float weight)
        : item(name, id, price, quantity){
            
         this -> expiryDate = expiryDate;
         this -> weight= weight;
        }

    void displayDetails() {
        display();
        cout << "Expiry Date: " << expiryDate << endl;
        cout << "Weight : " << weight << "kg" << endl;
        
    }

    ~Grocery() {
        cout << "Cleaning up Grocery item." << endl;
    }
};

int main()
{
    
    int n;
    std::cout << "no of items in the inventory" << std::endl;
    std::cin >> n;
    
    item **inventory = new item*[n];
   // int* type = new int[n];
    
    int category;
    for(int i =0 ; i<n;i++){
        
        
        
        std::cout << "select 1 for elec ans select 2 for Grocery" << std::endl;
        
        std::cin >> category;
        
        string name;
        int id;
        float price;
        int quantity;
        
        
        cout << "Enter item name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter ID: ";
        cin >> id;

        cout << "Enter price: ";
        cin >> price;

        cout << "Enter quantity: ";
        cin >> quantity;
        
        
        if(category == 1){
            int warrantyyears;
            float powerusage;
            
            std::cout << "enter warrenty and power consuption details" << std::endl;
            
            std::cin >> warrantyyears;
            
            std::cin >> powerusage;
            
            inventory[i] = new Electronics(name, id, price, quantity, warrantyyears, powerusage);
        }else if (category==2){
            string expiryDate;
            float weight;
        
        std::cout << "enter expiry and weight" << std::endl;
        
        std::cin >> expiryDate;
        std::cin >> weight;
        
        inventory[i] = new Grocery(name, id, price, quantity, expiryDate, weight);
    }
    
    else{
        std::cout << "invalid category" << std::endl;
    }
    
    
    }
    
    
    for(int i = 0 ; i<n ; i++){
        
        
        if(category==1){
            
            
            Electronics* e = (Electronics*)inventory[i];
            
            e->displayDetails();
            
        }else if(category==2){
            
            Grocery* g = (Grocery*)inventory[i];
            g->displayDetails();
            
        }
        
       
    }
    
    }
    
    
    


