/*
Hour Angle ==>
12 hour ==> 360
1 hour ==> 30.

Angle made by hour clock per minute.
60 minute ==> 30 degree(as it moves by 1 hour)
1 minute ==> .5 degree.

Minute Angle ==>
60 minute ==> 360
1 minute ==> 6 

*/

double angleClock(int hour, int minutes)
{
    int HourFactor = hour>=12?hour-12:hour;
    float HourAngle = HourFactor*30+minutes*(0.5);
    float MinAngle = minutes*6;
    
    float diff = HourAngle - MinAngle;
    diff = diff < 0 ? -diff :diff;
    
    return (360 - diff) < diff ? (360 - diff):diff;
}


