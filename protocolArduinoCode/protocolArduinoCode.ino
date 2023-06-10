#define in1 5
#define in2 6
#define in3 10
#define in4 11
int command;
int duration;
int speed = 255;
void setup()
{
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    Serial.begin(9600);
}
void loop()
{
    if (Serial.available() > 0)
    {
        String input = Serial.readStringUntil('-');
        command = input.charAt(0);
        duration = input.substring(1).toInt();
        Stop();
        switch (command)
        {
        case 'F':
            forward(duration);
            break;
        case 'B':
            back(duration);
            break;
        case 'L':
            left(duration);
            break;
        case 'R':
            right(duration);
            break;
        }
    }
}
void forward(int duration)
{
    digitalWrite(in1, HIGH);
    digitalWrite(in3, HIGH);
    delay(duration * 1000);
    Stop();
}
void back(int duration)
{
    digitalWrite(in2, HIGH);
    digitalWrite(in4, HIGH);
    delay(duration * 1000);
    Stop();
}
void left(int duration)
{
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    delay(duration * 1000);
    Stop();
}
void right(int duration)
{
    digitalWrite(in1, HIGH);
    digitalWrite(in4, HIGH);
    delay(duration * 1000);
    Stop();
}
void Stop()
{
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}
