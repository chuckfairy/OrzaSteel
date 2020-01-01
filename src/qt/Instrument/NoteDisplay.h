/**
 * Neck
 */
#pragma once

#include <cstdint>
#include <vector>
#include <string>

#include <QtGui>
#include <QWidget>
#include <QLabel>


using std::vector;


namespace Orza { namespace Steel { namespace Instrument {


class NoteDisplay : public QWidget {

	public:

		explicit NoteDisplay(QLabel * widget);
		~NoteDisplay() {};

		/**
		 * Main update
		 */

		void update(vector<float_t>);

	private:

		QLabel * _widget;

};

} } }

