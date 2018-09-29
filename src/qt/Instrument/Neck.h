/**
 * Neck
 */
#pragma once

#include <cmath>
#include <cstdint>
#include <vector>

#include <QtGui>
#include <QWidget>
#include <QVBoxLayout>

#include "Tonebar.h"


using std::vector;


namespace Orza { namespace Steel { namespace Instrument {


class Neck : public QWidget {

	public:

		Neck();
		~Neck() {};

		/**
		 * setter for positions creation
		 */

		void setPositions( uint8_t );

		/**
		 * Get positions from bridge setup
		 */

		vector<float_t> getPositions();


		/**
		 * Obj getters
		 */

		Tonebar * getTonebar() {

			return _Bar;

		};


		/**
		 * Needs updating outside
		 */

		bool hasChange() {

			return HAS_CHANGE;

		};

		void setChanged() {

			HAS_CHANGE = false;

		};


	protected:

		/**
		 * Qt event overrides
		 */

		void mouseMoveEvent( QMouseEvent * event );


	private:

		/**
		 * Props
		 */

		vector<float_t> _positions;

		QVBoxLayout * _layout;

		bool HAS_CHANGE = false;


		/**
		 * Tonebar
		 */

		Tonebar * _Bar;


		/**
		 * Internals
		 */

		void createBridgeArea( uint8_t );

        void setupBridgeUIHelper();

        void setupBridgeUIHelperLog();

};

} } }
