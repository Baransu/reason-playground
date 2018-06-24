let inMemoryCache = ApolloInMemoryCache.createInMemoryCache();

let uri = "https://api.github.com/graphql?access_token=a6519ce3084aa49ecc9282372ccf4d81a0c8452d";
let httpLink = ApolloLinks.createHttpLink(~uri, ());

let instance =
  ReasonApollo.createApolloClient(~link=httpLink, ~cache=inMemoryCache, ());