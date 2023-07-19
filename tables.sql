PRAGMA FOREIGN_KEYS = ON;
.mode columns
.headers on


--tables

DROP TABLE IF EXISTS Match;
DROP TABLE IF EXISTS Edition;
DROP TABLE IF EXISTS Competition;
DROP TABLE IF EXISTS Player;

CREATE TABLE Player (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    date DATE,
    nacionality TEXT NOT NULL
);


CREATE TABLE Competition(
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    country TEXT NOT NULL
);

CREATE TABLE Edition(
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    year INTEGER NOT NULL,
    idCompetition INTEGER NOT NULL,
    CONSTRAINT year_check CHECK (year > 0),
    FOREIGN KEY (idCompetition) REFERENCES Competition(id)
);

CREATE TABLE Match(
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    idPlayer1 INTEGER,
    idPlayer2 INTEGER,
    idEdition INTEGER,
    state TEXT DEFAULT 'Finished',
    date DATETIME,
    FOREIGN KEY (idPlayer1) REFERENCES Player(id),
    FOREIGN KEY (idPlayer2) REFERENCES Player(id),
    FOREIGN KEY (idEdition) REFERENCES Edition(id)
);


--inserts

INSERT INTO Competition VALUES (1, 'Wimbledon', 'UK');
INSERT INTO Competition VALUES (2, 'Estoril Open', 'Portugal');

INSERT INTO Edition VALUES (1, 2023, 1);
INSERT INTO Edition VALUES (2, 2022, 2);
INSERT INTO Edition VALUES (3, 2021, 2);

INSERT INTO Player VALUES (1, 'Novak Djokovic', '22-05-1987', 'Serbia');
INSERT INTO Player VALUES (2, 'Sebastian Baez', '28-12-2000', 'Argentina');
INSERT INTO Player VALUES (3, 'Tomas Barrios Vera', '10-12-1997', 'Chile');
INSERT INTO Player VALUES (4, 'Lorenzo Musetti', '03-03-2002', 'Italy');
INSERT INTO Player VALUES (5, 'Juan Pablo Varillas', '06-10-1995', 'Peru');
INSERT INTO Player VALUES (6, 'Jordan Thompson', '20-04-1994', 'Australia');
INSERT INTO Player VALUES (7, 'Brandom Nakashima', '03-08-2001', 'USA');
INSERT INTO Player VALUES (8, 'Luca van Assche', '11-05-2004', 'France');
INSERT INTO Player VALUES (9, 'Aslan Karatsev', '04-09-1993', 'Russia');
INSERT INTO Player VALUES (10, 'Andrey Rublev', '20-10-1997', 'Russia');
INSERT INTO Player VALUES (11, 'Max Purcell', '03-04-1998', 'Australia');
INSERT INTO Player VALUES (12, 'Filip Krajinovic', '27-02-1992', 'Serbia');
INSERT INTO Player VALUES (13, 'Felix Auger-Aliassime', '08-08-2000', 'Canada');
INSERT INTO Player VALUES (14, 'Maximilian Marterer', '15-06-1995', 'Germany');
INSERT INTO Player VALUES (15, 'Borna Gojo', '27-02-1998', 'Croatia');
INSERT INTO Player VALUES (16, 'Albert Ramos-Vinolas', '17-01-1988', 'Spain');
INSERT INTO Player VALUES (17, 'Hubert Hurkacz', '11-02-1997', 'Poland');
INSERT INTO Player VALUES (18, 'Pedro Cachin', '12-04-1995', 'Argentina');
INSERT INTO Player VALUES (19, 'Michale Mmoh', '10-01-1998', 'USA');
INSERT INTO Player VALUES (20, 'David Goffin', '07-12-1990', 'Belgium');
INSERT INTO Player VALUES (21, 'Fabian Marozsan', '08-10-1999', 'Hungary');
INSERT INTO Player VALUES (22, 'Corentin Moutet', '19-04-1999', 'France');
INSERT INTO Player VALUES (23, 'Richard Gasquet', '18-06-1986', 'France');
INSERT INTO Player VALUES (24, 'Liam Broady', '04-01-1994', 'UK');
INSERT INTO Player VALUES (25, 'Constant Lestienne', '23-05-1992', 'France');
INSERT INTO Player VALUES (26, 'John Isner', '26-04-1985', 'USA');
INSERT INTO Player VALUES (27, 'Jaume Munar', '05-05-1997', 'Spain');
INSERT INTO Player VALUES (28, 'Jeffrey John Wolf', '21-12-1998', 'USA');
INSERT INTO Player VALUES (29, 'Enzo Couacaud', '01-03-1995', 'France');
INSERT INTO Player VALUES (30, 'Nick Kyrgios', '27-04-1995', 'Australia');
INSERT INTO Player VALUES (31, 'Laurent Lokoli', '18-10-1994', 'France');
INSERT INTO Player VALUES (32, 'Casper Ruud', '22-12-1998', 'Norway');
INSERT INTO Player VALUES (33, 'Jan Choinski', '10-06-1996', 'UK');
INSERT INTO Player VALUES (34, 'Dusan Lajovic', '30-06-1990', 'Serbia');
INSERT INTO Player VALUES (35, 'Nuno Borges', '19-02-1997', 'Portugal');
INSERT INTO Player VALUES (36, 'Mikael Ymer', '09-09-1998', 'Sweden');
INSERT INTO Player VALUES (37, 'Alex Molcan', '01-12-1997', 'Slovakia');
INSERT INTO Player VALUES (38, 'Dominik Keopfer', '29-04-1994', 'Germany');
INSERT INTO Player VALUES (39, 'Oscar Otte', '16-07-1993', 'Germany');
INSERT INTO Player VALUES (40, 'Alexander Bublik', '17-06-1997', 'Kazakhstan');
INSERT INTO Player VALUES (41, 'Mackenzie McDonald', '16-04-1995', 'USA');
INSERT INTO Player VALUES (42, 'Yannick Hanfmann', '13-11-1991', 'Germany');
INSERT INTO Player VALUES (43, 'Taylor Fritz', '28-10-1997', 'USA');
INSERT INTO Player VALUES (44, 'Roman Safiullin', '07-08-1997', 'Russia');
INSERT INTO Player VALUES (45, 'Roberto Bautista-Agut', '14-04-1988', 'Spain');
INSERT INTO Player VALUES (46, 'Aleksander Vukic', '06-04-1996', 'Russia');
INSERT INTO Player VALUES (47, 'Daniel Altmaier', '12-09-1998', 'Germany');
INSERT INTO Player VALUES (48, 'Tomas Martin Etcheverry', '18-07-1999', 'Argentina');
INSERT INTO Player VALUES (49, 'Bernabe Zapata Miralles', '12-01-1997', 'Spain');
INSERT INTO Player VALUES (50, 'Miomir Kecmanovic', '31-08-1999', 'Serbia');
INSERT INTO Player VALUES (51, 'Diego Schwartzmann', '16-08-1992', 'Argentina');
INSERT INTO Player VALUES (52, 'Emil Ruusuvuori', '02-04-1999', 'Finland');
INSERT INTO Player VALUES (53, 'Stan Wawrinka', '28-03-1985', 'Switzerland');
INSERT INTO Player VALUES (54, 'Yoshihito Nishioka', '27-09-1995', 'Japan');
INSERT INTO Player VALUES (55, 'Daniel Elahi Galan', '18-06-1996', 'Colombia');
INSERT INTO Player VALUES (56, 'Quentin Halys', '26-10-1996', 'France');
INSERT INTO Player VALUES (57, 'Daniel Evans', '23-05-1990', 'UK');
INSERT INTO Player VALUES (58, 'Borna Coric', '14-11-1996', 'Croatia');
INSERT INTO Player VALUES (59, 'Guido Pella', '17-05-1990', 'Argentina');
INSERT INTO Player VALUES (60, 'Denis Shapovalov', '15-04-1999', 'Canada');
INSERT INTO Player VALUES (61, 'Radu Albot', '11-11-1989', 'Moldavia');
INSERT INTO Player VALUES (62, 'Jannik Sinner', '16-08-2001', 'Italy');
INSERT INTO Player VALUES (63, 'Juan Manuel Cerundolo', '15-11-2001', 'Argentina');
INSERT INTO Player VALUES (64, 'Benjamin Bonzi', '09-06-1996', 'France');
INSERT INTO Player VALUES (65, 'Harold Mayot', '04-02-2002', 'France');
INSERT INTO Player VALUES (66, 'Lloyd Harris', '24-02-1997', 'South Africa');
INSERT INTO Player VALUES (67, 'Gregoire Barrere', '16-02-1994', 'France');
INSERT INTO Player VALUES (68, 'Matteo Berrettini', '12-04-1996', 'Italy');
INSERT INTO Player VALUES (69, 'Lorenzo Sonego', '11-05-1995', 'Italy');
INSERT INTO Player VALUES (70, 'Marton Fucsovics', '08-02-1992', 'Hungary');
INSERT INTO Player VALUES (71, 'Tallon Griekspoor', '02-07-1996', 'Netherlands');
INSERT INTO Player VALUES (72, 'Marcos Giron', '24-07-1993', 'USA');
INSERT INTO Player VALUES (73, 'Hugo Dellien', '16-06-1993', 'Bolivia');
INSERT INTO Player VALUES (74, 'George Loffhagen', '19-04-2001', 'UK');
INSERT INTO Player VALUES (75, 'Holger Rune', '29-04-2003', 'Denmark');
INSERT INTO Player VALUES (76, 'Alexandre Muller', '01-02-1997', 'France');
INSERT INTO Player VALUES (77, 'Arthur Rinderknech', '23-07-1995', 'France');
INSERT INTO Player VALUES (78, "Christopher O'Connell", '03-06-1994', 'Australia');
INSERT INTO Player VALUES (79, 'Hamad Medjedovic', '18-07-2003', 'Serbia');
INSERT INTO Player VALUES (80, 'Ben Shelton', '09-10-2002', 'USA');
INSERT INTO Player VALUES (81, 'Taro Daniel', '27-01-1993', 'Japan');
INSERT INTO Player VALUES (82, 'Dominic Thiem', '03-09-1993', 'Austria');
INSERT INTO Player VALUES (83, 'Stefanos Tsitsipas', '12-08-1998', 'Greece');
INSERT INTO Player VALUES (84, 'Matteo Arnaldi', '22-02-2001', 'Italy');
INSERT INTO Player VALUES (85, 'Roberto Carballes Baena', '23-03-1993', 'Spain');
INSERT INTO Player VALUES (86, 'Kimmer Coppejans', '07-02-1994', 'Belgium');
INSERT INTO Player VALUES (87, 'Alex de Minaur', '17-02-1999', 'Australia');
INSERT INTO Player VALUES (88, 'Maxime Cressy', '08-05-1997', 'USA');
INSERT INTO Player VALUES (89, 'Laslo Djere', '02-06-1995', 'Serbia');
INSERT INTO Player VALUES (90, 'Jiri Lehecka', '08-11-2001', 'Czech Republic');
INSERT INTO Player VALUES (91, 'Sebastian Ofner', '12-05-1996', 'Austria');
INSERT INTO Player VALUES (92, 'Milos Raonic', '27-12-1990', 'Canada');
INSERT INTO Player VALUES (93, 'Dennis Novak', '28-08-1993', 'Austria');
INSERT INTO Player VALUES (94, 'Jiri Vesely', '10-07-1993', 'Czech Republic');
INSERT INTO Player VALUES (95, 'Sebastian Korda', '05-07-2000', 'USA');
INSERT INTO Player VALUES (96, 'Carlos Alcaraz', '05-05-2003', 'Spain');
INSERT INTO Player VALUES (97, 'Jeremy Chardy', '12-02-1987', 'France');
INSERT INTO Player VALUES (98, 'Francisco Cerundolo', '13-08-1998', 'Argentina');
INSERT INTO Player VALUES (99, 'Christopher Eubanks', '05-05-1996', 'USA');
INSERT INTO Player VALUES (100, 'Thiago Monteiro', '31-05-1994', 'Brazil');
INSERT INTO Player VALUES (101, 'Marco Cecchinato', '30-09-1992', 'Italy');
INSERT INTO Player VALUES (102, 'Nicolas Jarry', '11-10-1995', 'Chile');
INSERT INTO Player VALUES (103, 'Alejandro Davidovich Fokina', '05-06-1999', 'Spain');
INSERT INTO Player VALUES (104, 'Arthur Fils', '12-06-2004', 'France');
INSERT INTO Player VALUES (105, 'Marc-Andrea Huesler', '24-06-1996', 'Switzerland');
INSERT INTO Player VALUES (106, 'Yosuke Watanuki', '12-04-1998', 'Japan');
INSERT INTO Player VALUES (107, 'Ilya Ivashka', '24-02-1994', 'Belarus');
INSERT INTO Player VALUES (108, 'Federico Coria', '09-03-1992', 'Argentina');
INSERT INTO Player VALUES (109, 'Adrian Mannarino', '29-06-1988', 'France');
INSERT INTO Player VALUES (110, 'Alexander Shevchenko', '29-11-2000', 'Russia');
INSERT INTO Player VALUES (111, 'Dominic Stricker', '16-08-2002', 'Switzerland');
INSERT INTO Player VALUES (112, 'Alexei Popyrin', '05-08-1999', 'Australia');
INSERT INTO Player VALUES (113, 'Jason Kubler', '19-05-1993', 'Australia');
INSERT INTO Player VALUES (114, 'Ugo Humbert', '16-06-1998', 'France');
INSERT INTO Player VALUES (115, 'Cameron Norrie', '23-08-1995', 'UK');
INSERT INTO Player VALUES (116, 'Tomas Machac', '13-10-2000', 'Czech Republic');
INSERT INTO Player VALUES (117, 'Alexander Zverev', '20-04-1997', 'Germany');
INSERT INTO Player VALUES (118, 'Gijs Brouwer', '14-03-1996', 'Netherlands');
INSERT INTO Player VALUES (119, 'Sho Shimabukuro', '30-07-1997', 'Japan');
INSERT INTO Player VALUES (120, 'Grigor Dimitrov', '16-05-1991', 'Belarus');
INSERT INTO Player VALUES (121, 'Ryan Peniston', '10-11-1995', 'UK');
INSERT INTO Player VALUES (122, 'Andy Murray', '15-05-1987', 'UK');
INSERT INTO Player VALUES (123, 'Shintaro Mochizuki', '02-06-2003', 'Japan');
INSERT INTO Player VALUES (124, 'Tommy Paul', '17-05-1997', 'USA');
INSERT INTO Player VALUES (125, 'Zhizhen Zhang', '16-10-1996', 'China');
INSERT INTO Player VALUES (126, 'Botic Van De Zandschulp', '04-10-1995', 'Netherlands');
INSERT INTO Player VALUES (127, 'Daniil Medvedev', '11-02-1996', 'Russia');
INSERT INTO Player VALUES (128, 'Arthur Fery', '12-07-2002', 'UK');
INSERT INTO Player VALUES (129, 'Frances Tiafoe', '20-01-1998', 'USA');
INSERT INTO Player VALUES (130, 'Yibing Wu', '14-10-1999', 'China');

INSERT INTO Match (id, idPlayer1, idPlayer2, idEdition, date) VALUES (1, 2, 3, 1, '2023-07-03 11:10:00');
INSERT INTO Match (id, idPlayer1, idPlayer2, idEdition, date) VALUES (2, 4, 5, 1, '2023-07-03 11:10:00');
INSERT INTO Match (id, idPlayer1, idPlayer2, idEdition, date) VALUES (3, 6, 7, 1, '2023-07-03 11:10:00');
INSERT INTO Match (id, idPlayer1, idPlayer2, idEdition, date) VALUES (4, 8, 9, 1, '2023-07-03 11:10:00');
INSERT INTO Match (id, idPlayer1, idPlayer2, idEdition, date) VALUES (5, 10, 11, 1, '2023-07-03 11:15:00');
INSERT INTO Match VALUES (6, 12, 13, 1, 'Cancelled', '2023-07-03 12:30:00');
INSERT INTO Match (id, idPlayer1, idPlayer2, idEdition, date) VALUES (7, 14, 15, 1, '2023-07-03 12:50:00');
INSERT INTO Match (id, idPlayer1, idPlayer2, idEdition, date) VALUES (8, 16, 17, 1, '2023-07-03 13:15:00');
INSERT INTO Match (id, idPlayer1, idPlayer2, idEdition, date) VALUES (9, 18, 1, 1, '2023-07-03 13:40:00');
INSERT INTO Match (id, idPlayer1, idPlayer2, idEdition, date) VALUES (10, 19, 13, 1, '2023-07-03 13:50:00');
INSERT INTO Match (id, idPlayer1, idPlayer2, idEdition, date) VALUES (11, 20, 21, 1, '2023-07-03 13:55:00');
INSERT INTO Match (id, idPlayer1, idPlayer2, idEdition, date) VALUES (12, 22, 23, 1, '2023-07-03 13:55:00');
INSERT INTO Match (id, idPlayer1, idPlayer2, idEdition, date) VALUES (13, 24, 25, 1, '2023-07-03 14:05:00');
INSERT INTO Match (id, idPlayer1, idPlayer2, idEdition, date) VALUES (14, 26, 27, 1, '2023-07-03 14:10:00');
INSERT INTO Match (id, idPlayer1, idPlayer2, idEdition, date) VALUES (15, 28, 29, 1, '2023-07-03 14:10:00');
INSERT INTO Match VALUES (16, 20, 30, 1, 'Cancelled', '2023-07-03 14:30:00');
INSERT INTO Match (id, idPlayer1, idPlayer2, idEdition, date) VALUES (17, 31, 32, 1, '2023-07-03 15:20:00');
INSERT INTO Match (id, idPlayer1, idPlayer2, idEdition, date) VALUES (18, 33, 34, 1, '2023-07-03 17:05:00');
INSERT INTO Match (id, idPlayer1, idPlayer2, idEdition, date) VALUES (19, 36, 37, 1, '2023-07-03 17:20:00');
INSERT INTO Match (id, idPlayer1, idPlayer2, idEdition, date) VALUES (20, 38, 39, 1, '2023-07-03 17:30:00');
INSERT INTO Match (id, idPlayer1, idPlayer2, idEdition, date) VALUES (21, 40, 41, 1, '2023-07-03 17:55:00');
INSERT INTO Match (id, idPlayer1, idPlayer2, idEdition, date) VALUES (22, 42, 43, 1, '2023-07-03 17:55:00');
INSERT INTO Match (id, idPlayer1, idPlayer2, idEdition, date) VALUES (23, 44, 45, 1, '2023-07-03 18:00:00');
INSERT INTO Match (id, idPlayer1, idPlayer2, idEdition, date) VALUES (24, 46, 47, 1, '2023-07-03 18:00:00');
INSERT INTO Match (id, idPlayer1, idPlayer2, idEdition, date) VALUES (25, 48, 49, 1, '2023-07-03 18:05:00');
INSERT INTO Match (id, idPlayer1, idPlayer2, idEdition, date) VALUES (26, 50, 51, 1, '2023-07-03 18:15:00');
INSERT INTO Match (id, idPlayer1, idPlayer2, idEdition, date) VALUES (27, 52, 53, 1, '2023-07-03 18:25:00');
INSERT INTO Match (id, idPlayer1, idPlayer2, idEdition, date) VALUES (28, 54, 55, 1, '2023-07-03 18:30:00');
INSERT INTO Match (id, idPlayer1, idPlayer2, idEdition, date) VALUES (29, 56, 57, 1, '2023-07-03 19:30:00');
INSERT INTO Match (id, idPlayer1, idPlayer2, idEdition, date) VALUES (30, 58, 59, 1, '2023-07-03 19:40:00');
INSERT INTO Match (id, idPlayer1, idPlayer2, idEdition, date) VALUES (31, 60, 61, 1, '2023-07-03 19:45:00');
INSERT INTO Match (id, idPlayer1, idPlayer2, idEdition, date) VALUES (32, 62, 63, 1, '2023-07-03 19:45:00');
INSERT INTO Match (id, idPlayer1, idPlayer2, idEdition, date) VALUES (33, 64, 65, 1, '2023-07-03 19:50:00');