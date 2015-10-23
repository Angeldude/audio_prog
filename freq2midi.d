import std.stdio;
import std.math;

void main()
{
  double semitone_ratio = pow(2.0, 1.0/12.0);

  double c5 = 220.0 * pow(semitone_ratio, 3.0);
  double c0 = c5 * pow(0.5, 5.0);

  double frequency = 430.0;
  double fracmidi = log(frequency / c0) / log(semitone_ratio);


  int midinote1 = cast(int)(fracmidi + 0.5);
  int midinote2 = cast(int)(fracmidi - 0.5);

  double freq1 = c0 * pow(semitone_ratio, midinote1);
  double freq2 = c0 * pow(semitone_ratio, midinote2);

  int bend = cast(int)(100 *((frequency - freq1)/(freq1 - freq2)));


  writefln("The nearest MIDI note to the frequency %0.2f is %d", frequency, midinote1);
  writefln("with a pitchbend of %d%%", bend);

}
