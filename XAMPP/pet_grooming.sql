-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Dec 06, 2023 at 03:52 PM
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
-- Database: `pet_grooming`
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
(3, 'HafasBakar', 'abc123', 'Hafas_Bakar', 'norasist@gmail.com', 'Pahang'),
(4, 'HayuniHaron', 'abc123', 'SitiNurHayuni', 'hayuni@gmail.com', 'Pahang');

-- --------------------------------------------------------

--
-- Table structure for table `appointment`
--

CREATE TABLE `appointment` (
  `AppointmentID` varchar(5) NOT NULL,
  `PetID` varchar(5) NOT NULL,
  `StaffID` varchar(4) NOT NULL,
  `App_Date` date NOT NULL DEFAULT current_timestamp(),
  `App_Time` time NOT NULL,
  `App_Package` varchar(2) NOT NULL,
  `App_price` varchar(10) NOT NULL,
  `App_Duration` varchar(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `appointment`
--

INSERT INTO `appointment` (`AppointmentID`, `PetID`, `StaffID`, `App_Date`, `App_Time`, `App_Package`, `App_price`, `App_Duration`) VALUES
('A110', 'P1019', 'S102', '2023-10-10', '00:06:32', 'B', 'RM 60', '2.5 Hours'),
('A115', 'P1011', 'S105', '2023-10-19', '11:06:32', 'D', 'RM 100', '4 Hours'),
('A117', 'P1018', 'S104', '2023-09-11', '16:15:25', 'C', 'RM 62', '2.5 Hours');

-- --------------------------------------------------------

--
-- Table structure for table `customer`
--

CREATE TABLE `customer` (
  `CustomerID` int(11) NOT NULL,
  `username` varchar(15) NOT NULL,
  `password` varchar(15) NOT NULL,
  `fullname` varchar(25) NOT NULL,
  `email` varchar(30) NOT NULL,
  `address` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `customer`
--

INSERT INTO `customer` (`CustomerID`, `username`, `password`, `fullname`, `email`, `address`) VALUES
(11, 'Hafas', '123456', 'Muhammad_Hafas', 'norasist@gmail.com', 'Pahang'),
(14, 'Sahira', '123abc', 'daniabaharom', 'dania@gmail.com', 'kl');

-- --------------------------------------------------------

--
-- Table structure for table `payment`
--

CREATE TABLE `payment` (
  `PaymentID` varchar(5) NOT NULL,
  `CustomerID` varchar(4) NOT NULL,
  `Payment_Cost` float NOT NULL,
  `Payment_Date` date NOT NULL,
  `Payment_Status` varchar(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `payment`
--

INSERT INTO `payment` (`PaymentID`, `CustomerID`, `Payment_Cost`, `Payment_Date`, `Payment_Status`) VALUES
('R2040', 'C011', 100, '2023-10-19', 'Complete');

-- --------------------------------------------------------

--
-- Table structure for table `pet`
--

CREATE TABLE `pet` (
  `PetID` varchar(5) NOT NULL,
  `Pet_Name` varchar(15) NOT NULL,
  `Pet_Species` varchar(4) NOT NULL,
  `Pet_Gender` varchar(7) NOT NULL,
  `Pet_Breed` varchar(20) NOT NULL,
  `Pet_Age` varchar(3) NOT NULL,
  `Pet_Colour` varchar(30) NOT NULL,
  `Pet_Weight` varchar(8) NOT NULL,
  `CustomerID` varchar(4) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `pet`
--

INSERT INTO `pet` (`PetID`, `Pet_Name`, `Pet_Species`, `Pet_Gender`, `Pet_Breed`, `Pet_Age`, `Pet_Colour`, `Pet_Weight`, `CustomerID`) VALUES
('P1019', 'Sandy', 'Cat', 'Female', 'Birman', '6 m', 'White', '1.3 kg', 'C019'),
('P1011', 'Lake', 'Cat', 'Male', 'Bombay', '1 y', 'Grey', '2.1 kg', 'C011'),
('P1016', 'Boby', 'Cat', 'Male', 'Persian', '8 m', 'Grey', '2.0 kg', 'C016'),
('P1116', 'Belly', 'Cat', 'Female', 'Persian', '9 m', 'Grey', '2.5 kg', 'C016'),
('P1118', 'Tomy', 'Cat', 'Male', 'Persian', '8 m', 'Grey', '2.2 kg', 'C018');

-- --------------------------------------------------------

--
-- Table structure for table `staff`
--

CREATE TABLE `staff` (
  `StaffID` int(11) NOT NULL,
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

INSERT INTO `staff` (`StaffID`, `Staff_Username`, `Staff_Password`, `Staff_Fname`, `Staff_PNum`, `Staff_Email`, `Staff_Add`) VALUES
(1, 'Staff105', 'Pet_Grooming', 'Nur Amalina Binti Mahmud', '0118453965', 'S105_Grooms@gmail.com', 'No 6, Jlan Keluang Tasik Chini, Perak'),
(2, 'Staff102', 'Pet_Grooming', 'Siti Nurhayuni Haron', '0118453965', 'sitinrhyuni@gmail.com', ''),
(3, 'Staff104', 'Pet_Grooming', 'Nurul Qarina Radzi', '0198476625', 'nrlqarina@gmail.com', 'Kuaters Polis, KL'),
(4, 'Ahmad_Harith', 'abc123', 'AhamadHarith_Hafas', '', 'harith@gmail.com', 'KL');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `admin`
--
ALTER TABLE `admin`
  ADD PRIMARY KEY (`AdminID`);

--
-- Indexes for table `customer`
--
ALTER TABLE `customer`
  ADD PRIMARY KEY (`CustomerID`) USING BTREE;

--
-- Indexes for table `staff`
--
ALTER TABLE `staff`
  ADD PRIMARY KEY (`StaffID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `admin`
--
ALTER TABLE `admin`
  MODIFY `AdminID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT for table `customer`
--
ALTER TABLE `customer`
  MODIFY `CustomerID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=17;

--
-- AUTO_INCREMENT for table `staff`
--
ALTER TABLE `staff`
  MODIFY `StaffID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
