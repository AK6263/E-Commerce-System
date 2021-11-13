# E-Commerce-System
An Online E-commerce System better than Amazon. Amazon ki maa ka ************. 

# Changes to be made

- [ ] USER -> DisplayProduct -> Extra endline
- [ ] Correct rong Sepling and g
- [ ] Make sure the user doesn't use quantity more than the defined quantity in `products.dat`
- [ ] Subtract the quantity from `products.dat` after invoice is created
- [ ] Make the user exit option so that the user goes back to the user login rather than exiting.



## To run

Keep the working directory in E-Commerce-System
``` bash
gcc main.c -o ./bin/main ; ./bin/main
```
## Modules it will require

- Admin and User Login and Sign-up Options
- Database Manager (Functions that can add update and delete data)
    - Admin can add more products
    - User can add products to the shopping listand stuff
- Use terminal functions like gotoxy to create frontend


# User Functions

- Buying(), Delivery_Option(), Bill_Print()

# Admin Functions

- New_Products(), Remove_Products(), Search()

# Requirements

- Current Stocks of the product 
- Unique id for each product

# Database Structure

## Product database

The Product database has the following structure new id will be added depending on the last id value
```
PRODUCT NAME(string),QUANTITY(int),PRICE(float),ID(int)
```
The Following Code Snippet can be used 
``` c
fscanf(fptr, "%[^,],%d,%f,%d", product_name, &quantity, &price, &id);
```

