-- Create the database
CREATE DATABASE IF NOT EXISTS new_user;

-- Use the database
USE new_user;

-- Create the userx table
CREATE TABLE IF NOT EXISTS userx (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(50) NOT NULL,
    username VARCHAR(50) UNIQUE NOT NULL,
    password VARCHAR(50) NOT NULL, -- Storing hashed password as a string
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Example data insertion
-- This is optional and just to verify the table works correctly
INSERT INTO userx (name, username, password)
VALUES ('Test User', 'testuser', '123456'); -- Replace '123456' with your hashed password
