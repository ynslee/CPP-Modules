
#ifndef SAMPLE1_CLASS_H
# define SAMPLE1_CLASS_H

/**
 * Class Sample -> class(keyword) Sample(identifier)
 * declare constructor : Sample(void);
 * ~Sample is desconstructor.
 * Constuctor of instances, descontructor of instances
 */
class Sample1{

public:

	char	a1;
	int		a2;
	float	a3;

	Sample1(char p1, int p2, float p3);
	~Sample1(void);

};

#endif