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

	Q_OBJECT;

	public:

		explicit NoteDisplay(QLabel * widget);
		~NoteDisplay() {};


	public slots:

		void handleUpdate(vector<float_t>);


	signals:

		/**
		 * Main update
		 */

		void update(vector<float_t>);

	private:

		QLabel * _widget;

};

} } }

