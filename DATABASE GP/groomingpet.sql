-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jan 14, 2024 at 08:46 AM
-- Server version: 10.4.28-MariaDB
-- PHP Version: 8.2.4

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `groomingpet`
--

-- --------------------------------------------------------

--
-- Table structure for table `admin`
--

CREATE TABLE `admin` (
  `AdminID` int(11) NOT NULL,
  `Admin_Username` varchar(15) NOT NULL,
  `Admin_Password` varchar(16) NOT NULL,
  `Admin_Fname` varchar(50) NOT NULL,
  `Admin_Email` varchar(25) NOT NULL,
  `Admin_Add` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `admin`
--

INSERT INTO `admin` (`AdminID`, `Admin_Username`, `Admin_Password`, `Admin_Fname`, `Admin_Email`, `Admin_Add`) VALUES
(3, 'Admin', 'Admin123', 'Sahira Binti Muhammad Hafas', 'shrahfas@gmail.com', 'Pangsapuri Melur, KL');

-- --------------------------------------------------------

--
-- Table structure for table `appointment`
--

CREATE TABLE `appointment` (
  `AppointmentID` int(11) NOT NULL,
  `PetID` int(11) NOT NULL,
  `packageID` int(11) NOT NULL,
  `App_Date` date NOT NULL,
  `App_Time` time NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `appointment`
--

INSERT INTO `appointment` (`AppointmentID`, `PetID`, `packageID`, `App_Date`, `App_Time`) VALUES
(2, 2, 2, '2024-01-17', '11:06:32'),
(3, 2, 0, '2023-04-05', '00:14:30'),
(4, 3, 2, '2023-03-24', '00:14:30'),
(14, 4, 2, '2023-10-09', '00:14:20'),
(15, 2, 3, '2023-10-01', '00:13:30'),
(18, 2, 1, '2022-02-10', '00:13:00'),
(20, 2, 1, '2024-12-02', '00:13:00'),
(21, 2, 4, '2023-10-06', '00:14:40'),
(22, 2, 3, '2024-05-04', '00:15:30'),
(23, 2, 1, '2024-05-16', '00:13:00'),
(24, 2, 1, '2023-10-10', '00:14:30'),
(25, 2, 1, '2023-05-06', '00:16:00'),
(26, 2, 1, '2024-03-13', '00:14:00'),
(27, 2, 1, '2023-07-19', '00:14:00'),
(28, 2, 1, '2024-11-03', '00:15:30'),
(29, 2, 1, '2024-12-03', '00:14:50'),
(30, 2, 1, '2023-10-09', '00:13:00'),
(31, 2, 4, '2024-10-01', '00:13:00'),
(32, 2, 2, '2023-04-14', '00:13:00'),
(33, 3, 3, '2023-04-15', '00:14:00'),
(36, 2, 3, '2024-01-17', '00:14:00'),
(37, 2, 4, '2024-01-17', '00:14:00'),
(38, 0, 0, '2024-01-17', '00:00:00'),
(39, 2, 4, '2024-05-12', '00:15:00'),
(40, 2, 4, '2024-11-03', '00:15:00'),
(41, 2, 4, '2023-10-09', '00:14:00'),
(42, 2, 4, '2024-01-19', '00:14:00'),
(43, 2, 4, '2023-10-09', '00:14:30'),
(44, 2, 4, '2023-03-10', '00:14:00'),
(45, 2, 4, '2024-01-20', '00:14:00'),
(46, 3, 4, '2024-09-10', '00:14:00'),
(47, 3, 4, '2024-01-11', '00:15:30'),
(48, 3, 4, '2024-06-25', '00:14:00'),
(49, 3, 4, '2024-06-25', '00:13:00'),
(50, 3, 4, '2024-06-25', '00:14:30'),
(51, 3, 4, '2024-01-15', '00:14:00'),
(52, 3, 4, '2024-06-25', '00:14:00'),
(53, 3, 4, '2024-05-26', '00:14:00');

-- --------------------------------------------------------

--
-- Table structure for table `customer`
--

CREATE TABLE `customer` (
  `CustomerID` int(11) NOT NULL,
  `username` varchar(20) NOT NULL,
  `password` varchar(16) NOT NULL,
  `fullname` varchar(50) NOT NULL,
  `email` varchar(20) NOT NULL,
  `numphone` varchar(15) NOT NULL,
  `address` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `customer`
--

INSERT INTO `customer` (`CustomerID`, `username`, `password`, `fullname`, `email`, `numphone`, `address`) VALUES
(1, 'Danish', 'danish123', 'Ahmad Danish', 'dnshfas@gmail.com', '0108312954', 'melur, kl'),
(2, 'Hafas', 'hafas123', 'Muhammad Hafas Bin Bakar', 'norasist@gmail.com', '0193513371', 'Karak,Pahang'),
(3, 'Aaleya', '123456', 'Sahira Aaleya', 'apeapeje@gmail.com', '0185467728', ''),
(4, 'Aina', 'aina123', 'Aina Nabilah', 'matahari@gmail.com', '0129846672', 'kl, cheras');

-- --------------------------------------------------------

--
-- Table structure for table `package`
--

CREATE TABLE `package` (
  `packageID` int(11) NOT NULL,
  `price` decimal(10,2) NOT NULL,
  `package_name` varchar(30) NOT NULL,
  `Duration` varchar(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `package`
--

INSERT INTO `package` (`packageID`, `price`, `package_name`, `Duration`) VALUES
(1, 70.00, 'Basic Grooming', '2 hours'),
(2, 120.00, 'Fleas Treatment', '3 hours'),
(3, 150.00, 'Fungus Treatment', '3 hours'),
(4, 200.00, 'Full Body Tream', '4 hours');

-- --------------------------------------------------------

--
-- Table structure for table `payment`
--

CREATE TABLE `payment` (
  `paymentID` int(11) NOT NULL,
  `PetID` int(11) NOT NULL,
  `packageID` int(11) NOT NULL,
  `AppointmentID` int(11) NOT NULL,
  `dateTime` timestamp NOT NULL DEFAULT current_timestamp() ON UPDATE current_timestamp(),
  `Total_Payment` double(10,2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `payment`
--

INSERT INTO `payment` (`paymentID`, `PetID`, `packageID`, `AppointmentID`, `dateTime`, `Total_Payment`) VALUES
(1, 0, 2, 0, '2024-01-10 07:53:41', 120.00),
(2, 0, 3, 0, '2024-01-10 07:53:41', 150.00),
(3, 0, 2, 0, '2024-01-10 07:53:41', 120.00),
(4, 0, 4, 0, '2024-01-10 07:55:34', 200.00),
(5, 0, 4, 0, '2024-01-10 09:37:35', 200.00),
(6, 0, 1, 0, '2024-01-10 09:53:15', 100.00),
(7, 0, 4, 0, '2024-01-10 14:09:24', 200.00),
(8, 2, 1, 0, '2024-01-10 18:42:31', 100.00),
(9, 2, 1, 0, '2024-01-11 03:44:00', 0.00),
(10, 1, 2, 0, '2024-01-11 03:47:03', 0.00),
(11, 2, 2, 0, '2024-01-11 04:39:40', 150.00),
(12, 3, 3, 0, '2024-01-11 04:41:29', 180.00),
(13, 2, 4, 0, '2024-01-13 06:31:13', 230.00),
(19, 3, 4, 0, '2023-03-14 06:54:52', 230.00),
(30, 3, 4, 0, '2023-03-14 06:54:52', 230.00),
(31, 2, 4, 0, '2024-01-13 15:37:37', 230.00),
(32, 3, 4, 0, '2024-01-13 17:41:11', 230.00),
(33, 3, 4, 0, '2024-01-13 17:44:34', 230.00),
(34, 2, 4, 0, '2024-01-13 17:47:40', 230.00),
(35, 3, 4, 0, '2024-01-13 17:49:44', 230.00),
(36, 3, 4, 0, '2024-01-13 17:59:03', 230.00),
(37, 3, 4, 0, '2024-01-13 18:26:36', 230.00);

-- --------------------------------------------------------

--
-- Table structure for table `payment_package`
--

CREATE TABLE `payment_package` (
  `paymentID` int(11) NOT NULL,
  `packageID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `pet`
--

CREATE TABLE `pet` (
  `PetID` int(11) NOT NULL,
  `CustomerID` int(11) NOT NULL,
  `Pet_Name` varchar(15) NOT NULL,
  `Pet_Species` varchar(4) NOT NULL,
  `Pet_Gender` varchar(7) NOT NULL,
  `Pet_Breed` varchar(20) NOT NULL,
  `Pet_Age` varchar(15) NOT NULL,
  `Pet_Colour` varchar(30) NOT NULL,
  `Pet_Weight` varchar(15) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `pet`
--

INSERT INTO `pet` (`PetID`, `CustomerID`, `Pet_Name`, `Pet_Species`, `Pet_Gender`, `Pet_Breed`, `Pet_Age`, `Pet_Colour`, `Pet_Weight`) VALUES
(2, 1, 'Boby', 'Cat', 'Female', 'British Short Hair', '9 month', 'Grey', '1 kg'),
(3, 1, 'Sandy', 'Cat', 'Female', 'British short hair', '', 'White', ''),
(4, 2, 'Loly', 'Cat', 'Female', 'British short hair', '', 'Brown', '500 g'),
(6, 1, 'Belly', '', '', '', '', '', '');

-- --------------------------------------------------------

--
-- Table structure for table `staff`
--

CREATE TABLE `staff` (
  `StaffID` int(11) NOT NULL,
  `AdminID` int(11) NOT NULL,
  `Staff_Username` varchar(15) NOT NULL,
  `Staff_Password` varchar(16) NOT NULL,
  `Staff_Fname` varchar(50) NOT NULL,
  `Staff_PNum` varchar(11) NOT NULL,
  `Staff_Email` varchar(25) NOT NULL,
  `Staff_Add` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `staff`
--

INSERT INTO `staff` (`StaffID`, `AdminID`, `Staff_Username`, `Staff_Password`, `Staff_Fname`, `Staff_PNum`, `Staff_Email`, `Staff_Add`) VALUES
(3, 0, 'Imran', 'imran123', 'sdnsindwin', '0111111111', 'imran@gmail.com', 'Cheras, KL'),
(4, 3, 'Acha', 'acha123', 'Elyyana Natasha', '0174593739', 'acha@gmail.com', 'Manjung Gajah, Perak');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `admin`
--
ALTER TABLE `admin`
  ADD PRIMARY KEY (`AdminID`);

--
-- Indexes for table `appointment`
--
ALTER TABLE `appointment`
  ADD PRIMARY KEY (`AppointmentID`),
  ADD KEY `PetID` (`PetID`);

--
-- Indexes for table `customer`
--
ALTER TABLE `customer`
  ADD PRIMARY KEY (`CustomerID`);

--
-- Indexes for table `package`
--
ALTER TABLE `package`
  ADD PRIMARY KEY (`packageID`);

--
-- Indexes for table `payment`
--
ALTER TABLE `payment`
  ADD PRIMARY KEY (`paymentID`),
  ADD KEY `PetID` (`PetID`),
  ADD KEY `AppointmentID` (`AppointmentID`);

--
-- Indexes for table `pet`
--
ALTER TABLE `pet`
  ADD PRIMARY KEY (`PetID`),
  ADD KEY `CustomerID` (`CustomerID`);

--
-- Indexes for table `staff`
--
ALTER TABLE `staff`
  ADD PRIMARY KEY (`StaffID`),
  ADD KEY `AdminID` (`AdminID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `admin`
--
ALTER TABLE `admin`
  MODIFY `AdminID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT for table `appointment`
--
ALTER TABLE `appointment`
  MODIFY `AppointmentID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=54;

--
-- AUTO_INCREMENT for table `customer`
--
ALTER TABLE `customer`
  MODIFY `CustomerID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT for table `package`
--
ALTER TABLE `package`
  MODIFY `packageID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT for table `payment`
--
ALTER TABLE `payment`
  MODIFY `paymentID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=38;

--
-- AUTO_INCREMENT for table `pet`
--
ALTER TABLE `pet`
  MODIFY `PetID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT for table `staff`
--
ALTER TABLE `staff`
  MODIFY `StaffID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `payment`
--
ALTER TABLE `payment`
  ADD CONSTRAINT `payment_ibfk_2` FOREIGN KEY (`packageID`) REFERENCES `package` (`packageID`);

--
-- Constraints for table `pet`
--
ALTER TABLE `pet`
  ADD CONSTRAINT `pet_ibfk_1` FOREIGN KEY (`CustomerID`) REFERENCES `customer` (`CustomerID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
