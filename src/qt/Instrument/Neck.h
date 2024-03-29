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
#include "FretArea.h"


using std::vector;


namespace Orza { namespace Steel { namespace Instrument {


class Neck : public QWidget {

	Q_OBJECT;

	public:

		Neck();
		~Neck() {};


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

		void handleResize();


		/**
		 * Settings
		 */

		void setOctaves( int );

		void setSemiTones( int ); //@TODO


	public slots:

		/**
		 * setter for positions creation
		 */

		void setPositions( float );


	protected:

		/**
		 * Qt event overrides
		 */

		void mouseMoveEvent( QMouseEvent * event );

		void resizeEvent( QResizeEvent *event );


	signals:

		/**
		 * To change position on the right thread
		 */
		void emitNeckPosition( float );



	private:

		/**
		 * Props
		 */

		vector<float_t> _positions;

		QVBoxLayout * _layout;

		bool HAS_CHANGE = false;

		vector<FretArea*> _areas;

		int _semiTones = 12;
		int _octaves = 2;


		/**
		 * Tonebar
		 */

		Tonebar * _Bar;


		/**
		 * Internals
		 */

		void createBridgeArea( uint8_t );

		void setupBridgeUIHelper();

		void clearArea();

};

} } }
