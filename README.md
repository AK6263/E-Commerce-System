# E-Commerce-System
An Online E-commerce System better than Amazon. Amazon ki maa ka ************. 

## Modules it will require

- Admin and User Login and Sign-up Options
- Database Manager (Functions that can add update and delete data)
    - Admin can add more products
    - User can add products to the shopping listand stuff
- Use terminal functions like gotoxy to create frontend
## Product database

The Product database has the following structure new id will be added depending on the last id value
```
PRODUCT NAME(string) QUANTITY(int) PRICE(float) ID(int)
```
The Following Code Snippet can be used 
``` c
fscanf(fptr, "%[^,],%d,%f,%d", product_name, &quantity, &price, &id);
```
