-- SQL Example: Create and Query a Table

CREATE TABLE Employees (
    id INT PRIMARY KEY,
    name VARCHAR(50),
    salary DECIMAL(10, 2)
);

INSERT INTO Employees (id, name, salary)
VALUES (1, 'Alice', 50000), (2, 'Bob', 60000), (3, 'Charlie', 70000);

SELECT * FROM Employees WHERE salary > 55000;
