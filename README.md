# Seismic Event Detection

## Background:

Special sensors called seismometers are used to collect earth motion information including earthquakes and tidal motion. By analysing ground motion from an earthquake using data from several seismometers, it is possible to determine the epicentre of an earthquake and the intensity of the earthquake (normally measured using the Richter scale).

## Description:

Write a C++ Object Oriented program that reads seismometer data from a data (text) file named seismic.dat, determines whether seismic events have occurred, reports the data and findings to the screen in text and graphics format and stores the findings to a data file.

The first line of the seismic data file contains two values: the number of data elements or readings and the time interval in seconds that occurred between consecutive measurements. The time interval is a floating point value and it may be assumed that all the measurements were taken with the same time interval between them. After reading the data measurements the program should identify possible earthquakes or seismic events using a power ratio. 

At a specific point in time this ratio is the quotient of a short-time power measurement divided by a long -time power measurement. If the ratio is greater than a given threshold then an event may have occurred at that point in time.  

Given a specific point in the data measurements the short-time power is the average power, or average squared value, of the measurements using the specified point plus a small number of points that occurred just previous to the specified point. 

The long-time power is the average power of the measurements using the specified point plus a larger number of points that occurred just previous to the specified point. The set of points used in a calculation is referred to as a data window. 

The threshold is generally greater than 1 to avoid detecting events in constant data because the short-time power is equal to the long-time power if the data values are all the same value. 

The data window length (number of measurements) for short-time power and long-time power are to be read from the keyboard as is the threshold value. 

## Problem Statement:
Determine the locations of possible seismic events using a set of seismometer measurements from a data file. Write the times of possible events to a data file with the corresponding power ratio and threshold. The times of possible events and the corresponding power ratio and threshold should be reported to the PC screen in text and graphic mode. Demonstrate an Iterative approach in your algorithm and program development.
## Input / Output Description: 
The inputs to this program are:
the data (text) file named seismic.dat, the number of measurements to use for short time power and long time power, and the threshold value.

The outputs are:
1.	a screen report (text and graphics) giving the times of potential seismic events the corresponding short-time to long-time power ratio and threshold employed;
2.	a data file containing the times of potential seismic events, the corresponding short-time to long-time power ratio and threshold employed.

## Example: 
Suppose the data file contains the following data:

11 0.01 1 2 1 1 1 5 4 2 1 1 1 

Assuming a short -time window of 2 samples and
                 a long-time window of 5 samples and
                 a threshold of 1.5.

The first valid point is at time 0.04 for which 
Short-time power = (1+1)/2=1
Long-time power = (1+1+1+4+1)/5 = 1.6
Ratio = 1/1.6 = 0.63.
Threshold = 1.5.
Result - No event at time 0.04.

The next valid point is at time 0.05 for which 
Short-time power = (25+1)/2=13
Long-time power = (25+1+1+4)/5 = 6.4
Ratio = 13/6.4 = 2.03.
Threshold = 1.5.
Result - Event at time 0.05.

The next valid point is at time 0.06 for which 
Short-time power = (16+25)/2=20.5
Long-time power =  (16+25+1+1+1)/5 = 8.8
Ratio = 20.5/8.8 = 2.33.
Threshold = 1.5.
Result - Event at time 0.06 (Continuation from point 0.05).

The next valid point is at time 0.07 for which 
Short-time power = (4+16)/2=10
Long-time power =  (4+16+25+1+1)/5 = 9.4
Ratio = 10/9.4 = 1.06
Threshold = 1.5.
Result - No event at time 0.07.

etc. Continue to end of sequence.


**Note:** The first 4 points are invalid because the long-time window in this case needs 5 points. The 4 points can be handled by shortening the long-time window and short-time windows accordingly and noting in the reported results that the windows were shortened. Or simply ignore invalid points (i.e. points not covered by the windows) and note in the reported results which points were ignored. 

## Issues 
There could be some issues with a program & report. 
