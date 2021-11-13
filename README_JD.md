## Brief intro

* ```delivery.c```
  * Is supposed to 
      * set an <i>address</i>
      * fix a <i>time slot</i>
      * check availability of delivery van/ delivery facility
  * Should proceed to billing
  * Status: <i>Working</i>
  * Modification needed, ref to ToDo
* ```billing.c```
  * Is supposed to produce a bill...
  * And append the purchase details to a purchase-history doc
  * Generates a receipt in txt format, and displays on the CLI as well
  * Should come back to ```user.c``` after termination
  * Status: <i>Working</i>
## Comments

* ```time.txt``` (availability of delivery van in a particular slot) can be modified
* ```pin.txt```... pincode of the localities we are delivering to
* ```invoices.txt``` contain entire the purchase history

## ToDo

- [ ] ```delivery.c```: address to be passed to the billing stage