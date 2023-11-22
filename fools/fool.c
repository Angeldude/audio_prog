#include <stdio.h>
#include <portsf.h>

int main()
{
	psf_init();
	PSF_PROPS props;
	int sf;
	
	sf = psf_sndOpen("sample.wav", &props, 0);
	if(sf < 0){
		printf("Error!");
		return 1;
	}
	printf("Sample rate = %d", props.srate);
	psf_finish();
	return 0;
}