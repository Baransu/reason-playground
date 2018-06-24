let apiKey: string = [%raw {|process.env.REACT_APP_API_KEY|}];

let inMemoryCache = ApolloInMemoryCache.createInMemoryCache();

let uri = "https://api.github.com/graphql?access_token=" ++ apiKey;
let httpLink = ApolloLinks.createHttpLink(~uri, ());

let instance =
  ReasonApollo.createApolloClient(~link=httpLink, ~cache=inMemoryCache, ());