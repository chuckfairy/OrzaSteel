/**
 * String instrument frequency instrument
 */
#pragma once

#include <cmath>
#include <cstdint>
#include <map>
#include <vector>

#include "Pedal.h"


using std::map;
using std::vector;


namespace Orza { namespace Steel { namespace Audio {


class StringInstrument {

	public:

		/**
		 * Static neck types
		 */

		static vector<float_t> TYPE_DEFAULT;

		static vector<float_t> TYPE_COUNTRY_NECK;

		static vector<float_t> TYPE_COUNTRY_NECK_L;

		static vector<float_t> NECK_STEEL_STANDARD_10;

		static vector<float_t> TYPE_GUITAR_STANDARD;

		static vector<float_t> TYPE_GUITAR_DROP_D;


		/**
		 * Pedal types
		 */

		static vector<Pedal*> PEDAL_STANDARD_10;


		/**
		 * constructs
		 */

		StringInstrument();
		StringInstrument( vector<float_t> strings );


		/**
		 * Getters
		 */

		uint8_t getNumStrings();

		const vector<float_t> * getStrings() {

            return &_strings;

        };


		/**
		 * Get pitches from instruments
		 * from vector of strings => 0-100 on neck
		 */

		vector<float_t> getPitches( map<uint8_t, float_t> );

		vector<float_t> getPitches( vector<uint8_t> ); //Assumes position 0

		float_t getPitch( uint8_t stringNum, uint8_t position );


        /**
         * Pedal based
         */

		float_t getPedalModifier( uint8_t stringNum );

		const vector<Pedal*> * getPedals() {

            return &_pedals;

        };



		/**
		 * Set strings and create map
		 */

		void setStrings( vector<float_t> strings );

		void setString( uint8_t num, float_t freq );


		/**
		 * Pedal
		 */

		void clearPedals();

		void addPedal( Pedal * pedal );

		void addPedals( vector<Pedal*> );


	private:

		/**
		 * vector of starting fequencies and note
		 */

		vector<float_t> _strings;

		vector<Pedal*> _pedals;

};

} } }
