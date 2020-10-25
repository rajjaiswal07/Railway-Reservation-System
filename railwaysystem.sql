-- phpMyAdmin SQL Dump
-- version 4.9.0.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Oct 23, 2019 at 06:10 PM
-- Server version: 10.4.6-MariaDB
-- PHP Version: 7.3.8

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `railwaysystem`
--

-- --------------------------------------------------------

--
-- Table structure for table `bookedticket`
--

CREATE TABLE `bookedticket` (
  `id` int(11) NOT NULL,
  `name` varchar(255) NOT NULL,
  `phone` int(50) NOT NULL,
  `source` varchar(255) NOT NULL,
  `destination` varchar(255) NOT NULL,
  `date` varchar(255) NOT NULL,
  `seat` int(50) NOT NULL,
  `train_number` int(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `bookedticket`
--

INSERT INTO `bookedticket` (`id`, `name`, `phone`, `source`, `destination`, `date`, `seat`, `train_number`) VALUES
(1, 'raj', 89787866, 'miraroad', 'bhopal', '12/08/19', 7, 0);

-- --------------------------------------------------------

--
-- Table structure for table `traindetails`
--

CREATE TABLE `traindetails` (
  `id` int(10) NOT NULL,
  `train_number` varchar(255) NOT NULL,
  `train_name` varchar(255) NOT NULL,
  `start_place` varchar(255) NOT NULL,
  `destination_place` varchar(255) NOT NULL,
  `price` int(10) NOT NULL,
  `seat` varchar(10) NOT NULL,
  `time` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `traindetails`
--

INSERT INTO `traindetails` (`id`, `train_number`, `train_name`, `start_place`, `destination_place`, `price`, `seat`, `time`) VALUES
(2, '222', 'shatabdhi', 'borivali', 'bhopal', 600, '200', '1200'),
(3, '777', 'rajdhani1', 'bandra', 'indore', 350, '200', '12:00');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `bookedticket`
--
ALTER TABLE `bookedticket`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `traindetails`
--
ALTER TABLE `traindetails`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `bookedticket`
--
ALTER TABLE `bookedticket`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT for table `traindetails`
--
ALTER TABLE `traindetails`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
