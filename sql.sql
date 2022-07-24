
--Create a table called 'friends' and insert values
CREATE TABLE friends (userId INTEGER PRIMARY KEY AUTOINCREMENT, firstName TEXT NOT NULL, favoriteColor TEXT NOT NULL, allergies TEXT);

INSERT INTO friends (firstName, favoriteColor, allergies)
VALUES ("Fallulah", "blue", "mosquito bites");

INSERT INTO friends (firstName, favoriteColor, allergies)
VALUES ("Bradley", "magenta", "the sins of our fathers");

INSERT INTO friends (firstName, favoriteColor, allergies)
VALUES ("Hasheesh", "green", "mean people");

INSERT INTO friends (firstName, favoriteColor, allergies)
VALUES ("Lorna", "the color of the sky after a storm", "pork");


--show the table
SELECT * FROM friends;


--make various queries to 'friends' table
SELECT allergies FROM friends
WHERE userID = 2;

SELECT allergies FROM friends
WHERE userID IN (3, 4);

SELECT favoriteColor FROM friends
WHERE firstName LIKE "B%";

--update a row in the table and updated table
UPDATE friends SET favoriteColor = "red"
WHERE firstName = "Bradley";

SELECT * FROM friends;


