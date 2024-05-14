/*
 *
 *  Copyright (c) 2021
 *  name : Francis Banyikwa
 *  email: mhogomchungu@gmail.com
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <QByteArray>

#include "../engines.h"
#include "../utility.h"

class lux : public engines::engine::functions
{
public:
	static const char * testData() ;

	~lux() override ;
	lux( const engines&,const engines::engine&,QJsonObject&,const QString& downloadFolder ) ;

	class lux_dlFilter : public engines::engine::functions::filter
	{
	public:
		lux_dlFilter( const engines::engine&,int,QByteArray ) ;

		const QByteArray& operator()( const Logger::Data& e ) override ;

		~lux_dlFilter() override ;
	private:
		const QByteArray& doneDownloading( const QByteArray& ) ;
		QByteArray m_fileName ;
		QByteArray m_banner ;
		QByteArray m_tmp ;
		QByteArray m_title ;
		engines::engine::functions::preProcessing m_progress ;
		QByteArray m_downloadFolder ;
		Logger::locale m_locale ;
	} ;

	engines::engine::functions::DataFilter Filter( int ) override ;

	std::vector< engines::engine::functions::mediaInfo > mediaProperties( Logger&,const QByteArray& ) override ;

	std::vector< engines::engine::functions::mediaInfo > mediaProperties( Logger&,const QJsonArray& ) override ;

	void runCommandOnDownloadedFile( const QString&,const QString& ) override ;

	bool foundNetworkUrl( const QString& s ) override ;

	void updateDownLoadCmdOptions( const engines::engine::functions::updateOpts&,bool ) override ;

	engines::engine::functions::FilterOutPut filterOutput() override ;

	QString updateTextOnCompleteDownlod( const QString& uiText,
					     const QString& bkText,
					     const QString& downloadingOptions,
					     const engines::engine::functions::finishedState& ) override ;
private:
	const engines::engine& m_engine ;
	QString m_downloadFolder ;
};
