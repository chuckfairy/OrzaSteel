/**
 * Patchbay effects list and jack port connection
 *
 */
#pragma once

#include <jack/jack.h>

#include <Jack/StereoHostInterface.h>


namespace Orza { namespace Steel { namespace Instrument {


/**
 * Output stereo class
 */



class PortInterface : public Jack::StereoHostInterface {

    public:

        explicit PortInterface( jack_client_t * c ) :
            Jack::StereoHostInterface( c )
        {

            createPorts();

        };


        /**
         * Prefix virtual
         */

        const char * getPrefix() {

            return "steel-instrument";

        };

};

} } }
