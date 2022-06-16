-- MySQL dump 10.13  Distrib 8.0.29, for Linux (x86_64)
--
-- Host: 127.0.0.1    Database: Cinema
-- ------------------------------------------------------
-- Server version	8.0.29-0ubuntu0.20.04.3

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Current Database: `Cinema`
--

CREATE DATABASE /*!32312 IF NOT EXISTS*/ `Cinema` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;

USE `Cinema`;

--
-- Table structure for table `Bookings`
--

DROP TABLE IF EXISTS `Bookings`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Bookings` (
  `seatID` int unsigned NOT NULL,
  `userID` int unsigned NOT NULL,
  KEY `seatID` (`seatID`),
  KEY `userID` (`userID`),
  CONSTRAINT `Bookings_ibfk_1` FOREIGN KEY (`seatID`) REFERENCES `Seats` (`seatID`),
  CONSTRAINT `Bookings_ibfk_2` FOREIGN KEY (`userID`) REFERENCES `Users` (`userID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Bookings`
--

LOCK TABLES `Bookings` WRITE;
/*!40000 ALTER TABLE `Bookings` DISABLE KEYS */;
INSERT INTO `Bookings` VALUES (1,1),(5,1);
/*!40000 ALTER TABLE `Bookings` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Films`
--

DROP TABLE IF EXISTS `Films`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Films` (
  `filmID` int unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(63) DEFAULT NULL,
  `dates` date DEFAULT NULL,
  `time` time DEFAULT NULL,
  PRIMARY KEY (`filmID`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Films`
--

LOCK TABLES `Films` WRITE;
/*!40000 ALTER TABLE `Films` DISABLE KEYS */;
INSERT INTO `Films` VALUES (1,'Mission Impossible','2022-06-16','10:00:00'),(2,'Mission Impossible','2022-06-18','22:00:00'),(3,'Xmen','2022-06-20','10:00:00'),(4,'Xmen','2022-06-22','22:00:00');
/*!40000 ALTER TABLE `Films` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Seats`
--

DROP TABLE IF EXISTS `Seats`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Seats` (
  `seatID` int unsigned NOT NULL AUTO_INCREMENT,
  `seat` varchar(3) DEFAULT NULL,
  `booked` tinyint(1) DEFAULT NULL,
  `filmID` int unsigned NOT NULL,
  PRIMARY KEY (`seatID`),
  KEY `filmID` (`filmID`),
  CONSTRAINT `Seats_ibfk_1` FOREIGN KEY (`filmID`) REFERENCES `Films` (`filmID`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Seats`
--

LOCK TABLES `Seats` WRITE;
/*!40000 ALTER TABLE `Seats` DISABLE KEYS */;
INSERT INTO `Seats` VALUES (1,'A01',1,1),(2,'A02',0,1),(3,'B01',0,2),(4,'B02',0,2),(5,'C01',1,3),(6,'C02',0,3),(7,'D01',0,4),(8,'D02',0,4);
/*!40000 ALTER TABLE `Seats` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Users`
--

DROP TABLE IF EXISTS `Users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Users` (
  `userID` int unsigned NOT NULL AUTO_INCREMENT,
  `email` varchar(63) DEFAULT NULL,
  `password` varchar(63) DEFAULT NULL,
  PRIMARY KEY (`userID`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Users`
--

LOCK TABLES `Users` WRITE;
/*!40000 ALTER TABLE `Users` DISABLE KEYS */;
INSERT INTO `Users` VALUES (1,'sea@gmail.com','sea123');
/*!40000 ALTER TABLE `Users` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-06-16  6:43:59
