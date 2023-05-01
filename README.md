# contactPy
A MarieDB C++ microservice baced web app to save phone numbers

## MariaDB
  - This assumes MariaDB is installed. If not follow these instructions: https://www.digitalocean.com/community/tutorials/how-to-install-mariadb-on-ubuntu-22-04
  - Install the MariaDB connector: https://mariadb.com/docs/skysql/connect/programming-languages/cpp/install/

## Change the database credentials in ontactDB.h:
```
    #define DB_URL "jdbc:mariadb://localhost:3306/kenyon"
    #define USER "kenyon"
    #define PASS "GambierOwls"
```
## Setup web directory
 - sudo mkdir /var/www/html/contactPy
 - sudo chown ubuntu /var/www/html/contactPy

## Make and run
  - make
  - ./contactApp
# ContactCpp
# ContactCpp
