#include "Route.hpp"

namespace zf
{
    Route::Route()
        :start(zf::Grid(0,0)), end(zf::Grid(0,0))
    {
        path.push_back(start);
    }
    Route::Route(zf::Grid s, zf::Grid e)
        :start(s), end(e)
    {
        path.insert(path.begin(), s);
        if(start != end)
        {
            path.push_back(e);
        }
    }
    
    Route::Route(std::vector<zf::Grid> p)
        : start(p.front()), end(p.back()), path(p)
    {
    }


    bool Route::isRouteFor(zf::Grid s, zf::Grid e)
    {
        return start == s && end == e;
    }

    bool Route::mergeRoute(zf::Route& route1, zf::Route& route2, zf::Route& newRoute)
    {
        if(route1.end != route2.start && route1.end == route2.end && route1.start == route2.start && route1.path.size() > 1 && route2.path.size() > 1)
        {
            return false;
        }
        newRoute.start = route1.start;
        newRoute.end = route2.end;
        newRoute.path.clear();
        for(std::vector<zf::Grid>::iterator it = route1.path.begin() ; it != route1.path.end() ; ++it)
        {
            newRoute.path.push_back(*it); 
        }
        // iterate once, to skip the start of route2.
        for(std::vector<zf::Grid>::iterator it = (++(route2.path.begin())) ; it != route2.path.end() ; ++it)
        {
            newRoute.path.push_back(*it); 
        }
        return true;
    }
    
    bool constructRoute(std::vector<zf::Grid> path, zf::Route& route)
    {
        if(path.size() == 0)
        {
            return false;
        }
        route.start = path[0];
        route.end = path[path.size() - 1];
        route.path = path;
        return true;
    }
}
