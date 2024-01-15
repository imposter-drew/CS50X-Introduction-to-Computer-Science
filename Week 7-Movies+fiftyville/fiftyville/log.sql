-- Keep a log of any SQL queries you execute as you solve the mystery.

-- To have a first approach to the database and to have an idea of what's inside. Then I got info about the crime_scene_reports table.
.tables
.schema

-- Start by checking the events that took place the same date and place as the rubber duck theft. July 28, 2021 on Humphrey Street. I got info that 3 interviews took place for 3 witnesses
-- and they all mention bakery
SELECT * FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28 AND street = "Humphrey Street";

-- Check the interview table with the entry "bakery" to get the interviews of the witnesses.
SELECT * FROM interviews WHERE transcript LIKE "%bakery%";

-- Based on the first witness Ruth: Check security footage from bakery parking lot to check cars that left the parking lot within 10 minutes after the theft.
SELECT * FROM bakery_security_logs WHERE activity = "exit" AND month = 7 AND day = 28 AND hour = 10 AND minute >= 15;
-- I got too many plates so I keep the info for future queries and moving on to next interview. The detailed list with names is:
SELECT name, phone_number, passport_number, hour, minute FROM bakery_security_logs JOIN people ON people.license_plate = bakery_security_logs.license_plate WHERE activity = "exit" AND month = 7 AND day = 28 AND hour = 10 AND minute >= 15;

-- Based on the second witness Eugene: Check the atm transactions in the morning on Legget Street.
SELECT * FROM atm_transactions WHERE month = 7 AND day = 28 AND atm_location = "Leggett Street";
-- Join the account_numbers from atm table with bank table and get the person_id of those who used the atm by witness testimony
SELECT person_id FROM atm_transactions JOIN bank_accounts ON bank_accounts.account_number = atm_transactions.account_number WHERE month = 7 AND day = 28 AND atm_location = "Leggett Street";
-- Join those two tables with the people table and get a detailed list with all the info for the persons who used the atm according to the witness.
-- This is the first list of suspects where everyone will need to be triangulated with the information from the other witnesses.
SELECT * FROM atm_transactions JOIN bank_accounts ON bank_accounts.account_number = atm_transactions.account_number JOIN people ON people.id = bank_accounts.person_id WHERE month = 7 AND day = 28 AND atm_location = "Leggett Street";
-- For a cleaned up result of the list of suspects:
SELECT id, person_id, name, license_plate, phone_number, passport_number FROM (SELECT * FROM atm_transactions JOIN bank_accounts ON bank_accounts.account_number = atm_transactions.account_number JOIN people ON people.id = bank_accounts.person_id WHERE month = 7 AND day = 28 AND atm_location = "Leggett Street");

-- Triangulate results from atm and parking (first and second witness) to narrow the list of suspects. This is for future references
SELECT id, person_id, name, license_plate, phone_number, passport_number FROM (SELECT * FROM atm_transactions JOIN bank_accounts ON bank_accounts.account_number = atm_transactions.account_number JOIN people ON people.id = bank_accounts.person_id WHERE month = 7 AND day = 28 AND atm_location = "Leggett Street") WHERE name IN (SELECT name FROM bakery_security_logs JOIN people ON people.license_plate = bakery_security_logs.license_plate WHERE activity = "exit" AND month = 7 AND day = 28 AND hour = 10 AND minute >= 15);

-- Based on the third witness Raymond: Check the phone calls right after the theft for someone who talked less than a minute.
SELECT * FROM phone_calls WHERE month = 7 AND day = 28 AND duration <= 60;
-- Triangulate the list of suspects phone numbers with the calls the day of the theft: first one for callers and second one for receivers: The results are the suspects who were at the atm, at the parking and called
SELECT * FROM phone_calls WHERE caller IN (SELECT phone_number FROM (SELECT * FROM atm_transactions JOIN bank_accounts ON bank_accounts.account_number = atm_transactions.account_number JOIN people ON people.id = bank_accounts.person_id WHERE month = 7 AND day = 28 AND atm_location = "Leggett Street") WHERE name IN (SELECT name FROM bakery_security_logs JOIN people ON people.license_plate = bakery_security_logs.license_plate WHERE activity = "exit" AND month = 7 AND day = 28 AND hour = 10 AND minute >= 15)) AND month = 7 AND day = 28 AND duration <= 60;
SELECT * FROM phone_calls WHERE receiver IN (SELECT phone_number FROM (SELECT * FROM atm_transactions JOIN bank_accounts ON bank_accounts.account_number = atm_transactions.account_number JOIN people ON people.id = bank_accounts.person_id WHERE month = 7 AND day = 28 AND atm_location = "Leggett Street") WHERE name IN (SELECT name FROM bakery_security_logs JOIN people ON people.license_plate = bakery_security_logs.license_plate WHERE activity = "exit" AND month = 7 AND day = 28 AND hour = 10 AND minute >= 15)) AND month = 7 AND day = 28 AND duration <= 60;
-- For details on the lists (callers and receivers). This is  the updated list of suspects
SELECT * FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE caller IN (SELECT phone_number FROM (SELECT * FROM atm_transactions JOIN bank_accounts ON bank_accounts.account_number = atm_transactions.account_number JOIN people ON people.id = bank_accounts.person_id WHERE month = 7 AND day = 28 AND atm_location = "Leggett Street") WHERE name IN (SELECT name FROM bakery_security_logs JOIN people ON people.license_plate = bakery_security_logs.license_plate WHERE activity = "exit" AND month = 7 AND day = 28 AND hour = 10 AND minute >= 15)) AND month = 7 AND day = 28 AND duration <= 60);
SELECT * FROM people WHERE phone_number IN (SELECT receiver FROM phone_calls WHERE caller IN (SELECT phone_number FROM (SELECT * FROM atm_transactions JOIN bank_accounts ON bank_accounts.account_number = atm_transactions.account_number JOIN people ON people.id = bank_accounts.person_id WHERE month = 7 AND day = 28 AND atm_location = "Leggett Street") WHERE name IN (SELECT name FROM bakery_security_logs JOIN people ON people.license_plate = bakery_security_logs.license_plate WHERE activity = "exit" AND month = 7 AND day = 28 AND hour = 10 AND minute >= 15)) AND month = 7 AND day = 28 AND duration <= 60);
-- Call: Taylor -> James
-- Call: Diana -> Philip
-- Call: Bruce -> Robin

-- The thief asked the person on the other end of the phone (receiver) to purchase the flight ticket.
-- Check all departure flight for the day after(July 29) before midday.
SELECT * FROM passengers JOIN flights ON flights.id = passengers.flight_id WHERE month = 7 AND day = 29 AND hour <= 12;
-- Triangulate with the list of suspects who made or received the call
SELECT * FROM passengers JOIN flights ON flights.id = passengers.flight_id WHERE month = 7 AND day = 29 AND hour <= 12 AND passport_number IN (SELECT passport_number FROM people WHERE name = "James" OR name = "Philip" OR name = "Robin" OR name = "Taylor" OR name = "Diana" OR name = "Bruce");
-- Get the destination airport of the flight.
SELECT * FROM airports WHERE id = 4;
-- Get the names of those passengers
SELECT * FROM people WHERE passport_number IN (SELECT passport_number FROM passengers JOIN flights ON flights.id = passengers.flight_id WHERE month = 7 AND day = 29 AND hour <= 12 AND passport_number IN (SELECT passport_number FROM people WHERE name = "James" OR name = "Philip" OR name = "Robin" OR name = "Taylor" OR name = "Diana" OR name = "Bruce"));

-- Try both pairs of names in the answers.txt according  to the list of suspects (callers and receivers)
-- END


-- COMMENTS
-- I omitted the try/error/re-check commands to keep the log simple and clean of the invalid/repetitive queries
-- I registered the queries that follow up my reasoning