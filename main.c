//Program to open databse and print to console
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

static int callback(void *data, int argc, char **argv, char **azColName){
   int i;
   fprintf(stderr, "%s: ", (const char*)data);
   
   for(i = 0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   
   printf("\n");
   return 0;
}


int main(int argc, char* argv[]) {

    //connext to database and open
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    rc = sqlite3_open("first.db", &db);

   char *sql;
   const char* data = "Callback function called";


    //error message in case database does not open correctly
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   } else {
      fprintf(stderr, "----------------------------\n");
      fprintf(stderr, "Opened database successfully\n");
      fprintf(stderr, "----------------------------\n\n");
   }

   //Create SQL select statement 
   sql = "SELECT * from friends";

   //execute statement, displaying database
   rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
   

   //error handling
   if( rc != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "---------------------------\n");
      fprintf(stdout, "Operation done successfully\n");
      fprintf(stdout, "---------------------------\n");
   }


    //close database
    sqlite3_close(db);

}
