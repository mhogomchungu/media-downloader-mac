/*
*  Copyright (c) 2018
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

#include "../engines.h"

class encfs : public engines::engine
{
public:
	encfs() ;

	const QProcessEnvironment& getProcessEnvironment() const override ;

	void updateOptions( engines::engine::cmdArgsList&,bool ) const override ;

	engines::engine::args command( const QByteArray& password,
				       const engines::engine::cmdArgsList& args,
				       bool create ) const override ;

	void GUICreateOptions( const engines::engine::createGUIOptions& ) const override ;

	void GUIMountOptions( const engines::engine::mountGUIOptions& ) const override ;
private:
	mutable QString m_configPathThroughEnv ;
	mutable QProcessEnvironment m_environment ;
} ;
