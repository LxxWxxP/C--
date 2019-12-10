CREATE TABLE `clerk` (
  `id` char(12) NOT NULL,
  `name` char(20) NOT NULL,
  `department` char(20) NOT NULL,
  `leader` char(20) NOT NULL,
  `record` int(11) NOT NULL,
  `grade` int(11) NOT NULL,
  `attendence` char(10) check (attendence in ('attend','absences')),
  `not_pass_times` int(2),
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  UNIQUE KEY `name_UNIQUE` (`name`)
) 

